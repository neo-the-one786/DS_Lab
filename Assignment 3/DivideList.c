#include <stdio.h>
#include <stdlib.h>

typedef struct PNode {
    int data;
    int priority;
    struct PNode *next;
} PNode;

PNode *construct(int data, int priority) {
    PNode *this = (PNode *) malloc(sizeof(PNode));
    this->data = data;
    this->priority = priority;
    this->next = NULL;
    return this;
}

PNode *append(PNode *this, int data, int priority) {
    PNode *newNode = construct(data, priority);
    if (this == NULL) {
        this = newNode;
        return this;
    }
    PNode *ptr = this;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    return this;
}

void traverse(PNode *this) {
    PNode *ptr = this;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("null\n");
}

PNode **priotityDivide(PNode *this) {
    PNode **arr = (PNode **) malloc(5 * sizeof(PNode *));
    for (int i = 0; i < 5; i++) {
        PNode *ptr = this;
        PNode *head = NULL;
        while (ptr != NULL) {
            if (ptr->priority == i + 1) {
                head = append(head, ptr->data, ptr->priority);
            }
            ptr = ptr->next;
        }
        arr[i] = head;
    }
    return arr;
}

int main() {
    int len;
    printf("\nEnter list length: ");
    scanf("%d", &len);
    PNode *head = NULL;
    int data, priority;
    printf("\nEnter elements' data & priority: ");
    for (int i = 0; i < len; i++) {
        scanf("%d %d", &data, &priority);
        head = append(head, data, priority);
    }
    PNode **arr = priotityDivide(head);
    for (int i = 0; i < 5; i++) {
        traverse(arr[i]);
    }
    return 0;
}