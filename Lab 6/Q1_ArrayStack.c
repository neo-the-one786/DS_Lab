// 6.1 Write a menu driven program to create a stack using array and perform the following operation using
// function
// a. Push
// b. Pop
// c. check stack is empty or not
// d. check stack is full or not
// e. display stack elements

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int top, cpty, *arr;
} Stack;

Stack *construct(int cpty) {
    Stack *this = (Stack *) malloc(sizeof(Stack));
    this->top = -1;
    this->cpty = cpty;
    this->arr = (int *) calloc(this->cpty, sizeof(int));
    return this;
}

bool isEmpty(Stack *this) {
    return this->top == -1;
}

bool isFull(Stack *this) {
    return this->top == this->cpty - 1;
}

void push(Stack *this, int data) {
    if (isFull(this)) {
        fprintf(stderr, "\nStack Overflow!");
        return;
    }
    this->arr[++this->top] = data;
}

int pop(Stack *this) {
    if (isEmpty(this)) {
        fprintf(stderr, "\nStack Underflow!");
        return INT_MIN;
    }
    return this->arr[this->top--];
}

void display(Stack *this) {
    printf("\n[");
    for (int i = 0; i <= this->top; i++) {
        if (i > 0) {
            printf("%d, ", this->arr[i]);
        } else {
            printf("%d", this->arr[i]);
        }
    }
    printf("]\n");
}

int main() {
    int cpty, opt, data;
    printf("Enter stack capacity: ");
    scanf("%d", &cpty);
    Stack *stack = construct(cpty);
    do {
        printf("\nMain Menu\nEnter 1 to Push\nEnter 2 to Pop\nEnter 3 to IsEmpty\nEnter 4 to IsFull\nEnter 5 to Traverse\nEnter 6 to Exit");
        printf("\nEnter option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(stack, data);
                break;
            case 2:
                printf("\n%d popped\n", pop(stack));
                break;
            case 3:
                if (isEmpty(stack)) {
                    printf("\nTrue");
                } else {
                    printf("\nFalse");
                }
                break;
            case 4:
                if (isFull(stack)) {
                    printf("\nTrue");
                } else {
                    printf("\nFalse");
                }
                break;
            case 5:
                printf("\nStack: ");
                display(stack);
                break;
            case 6:
                free(stack->arr);
                free(stack);
                exit(0);
            default:
                printf("\nInvalid Input!\n");
                break;
        }
    } while (opt != 6);
    return 0;
}