// 3.6 Design algorithm to search an element in a doubly linked list, if found delete that node and insert that
// node at beginning. Otherwise display an appropriate message.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node *construct(int data) {
    Node *this = (Node *) malloc(sizeof(Node));
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
    return this;
}

Node *append(Node *this, int data) {
    Node *newNode = construct(data);
    if (this == NULL) {
        this = newNode;
        return this;
    }
    Node *ptr = this;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->prev = ptr;
    return this;
}

void traverse(Node *this) {
    Node *ptr = this;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("null\n");
}

void deleteAndPush(Node **this, int data) {
    if (*this == NULL) {
        fprintf(stderr, "\nNull Pointer!");
        return;
    } else if ((*this)->data == data) {
        return;
    }
    Node *ptr = *this;
    while (ptr->next != NULL) {
        if (ptr->next->data == data) {
            Node *temp = ptr->next;
            ptr->next = ptr->next->next;

            free(temp);
            break;
        }
        ptr = ptr->next;
    }
    Node *newNode = construct(data);
    newNode->next = *this;
    *this = newNode;
}

int main() {
    int len;
    printf("\nEnter list length: ");
    scanf("%d", &len);
    Node *head = NULL;
    int data;
    printf("\nEnter list elements: ");
    for (int i = 0; i < len; i++) {
        scanf("%d", &data);
        head = append(head, data);
    }
    int val;
    printf("\nEnter value to be extracted and pushed: ");
    scanf("%d", &val);
    deleteAndPush(&head, val);
    traverse(head);
    return 0;
}