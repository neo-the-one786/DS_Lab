// 6.2 Write a menu driven program to create a stack using linked list and perform the following operation
// using function
// a. Push
// b. Pop
// c. IsEmpty
// d. display the stack elements

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

Node *constructNode(int data) {
    Node *this = (Node *) malloc(sizeof(Node));
    this->data = data;
    this->next = NULL;
    return this;
}

Stack *constructStack() {
    Stack *this = (Stack *) malloc(sizeof(Stack));
    this->top = NULL;
    return this;
}

bool isEmpty(Stack *this) {
    return this->top == NULL;
}

void push(Stack *this, int data) {
    Node *newNode = constructNode(data);
    newNode->next = this->top;
    this->top = newNode;
}

int pop(Stack *this) {
    if (isEmpty(this)) {
        fprintf(stderr, "\nStack Underflow!");
        return INT_MIN;
    }
    Node *temp = this->top;
    this->top = this->top->next;
    int val = temp->data;
    free(temp);
    return val;
}

void traverse(Stack *this) {
    Node *ptr = this->top;
    printf("\n[");
    while (ptr != NULL) {
        if (ptr->next != NULL) {
            printf("%d, ", ptr->data);
        } else {
            printf("%d", ptr->data);
        }
        ptr = ptr->next;
    }
    printf("]\n");
}

int main() {
    int opt, data;
    Stack *stack = constructStack();
    do {
        printf("\nMain Menu\nEnter 1 to Push\nEnter 2 to Pop\nEnter 3 to IsEmpty\nEnter 4 to Traverse\nEnter 5 to Exit");
        printf("\nEnter option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                printf("\nEnter data: ");
                scanf("%d", &data);
                push(stack, data);
                break;
            case 2:
                printf("\nPopped %d", pop(stack));
                break;
            case 3:
                if (isEmpty(stack)) {
                    printf("\nTrue");
                } else {
                    printf("\nFalse");
                }
                break;
            case 4:
                traverse(stack);
                break;
            case 5:
                free(stack);
                exit(0);
            default:
                printf("\nInvalid input!");
                break;
        }
    } while (opt != 6);
    return 0;
}