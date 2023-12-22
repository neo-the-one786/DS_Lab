// 5.2 Write a program to create a circular linked list and display the elements of the list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *construct(int data) {
    Node *this = (Node *) malloc(sizeof(Node));
    if (this != NULL) {
        this->data = data;
        this->next = NULL;
    }
    return this;
}

void append(Node **this, int data) {
    Node *newNode = construct(data);
    if (*this == NULL) {
        *this = newNode;
        newNode->next = *this;
        return;
    }
    Node *current = *this;
    while (current->next != *this) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = *this;
}

void display(Node *this) {
    if (this == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }
    Node *ptr = this;
    do {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != this);
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    Node *head = NULL;
    int elem;
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &elem);
        append(&head, elem);
    }
    display(head);
    return 0;
}
