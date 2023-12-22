#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *banaao(int data) {
    Node *this = (Node *) malloc(sizeof(Node));
    this->data = data;
    this->next = this;
    return this;
}

void peechheSeGhusaao(Node **head, int data) {
    Node *newNode = banaao(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *ptr = *head;
    while (ptr->next != *head) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = *head;
}

void traverse(Node *head) {
    Node *ptr = head;
    do {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("head\n");
}

int main() {
    int len;
    printf("\nEnter list length: ");
    scanf("%d", &len);
    printf("\nEnter list elements: ");
    Node *head = NULL;
    int data;
    for (int i = 0; i < len; i++) {
        scanf("%d", &data);
        peechheSeGhusaao(&head, data);
    }
    traverse(head);
}