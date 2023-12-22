// 6.3 Write a program to convert infix expression to postfix operation using stack.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 50
typedef struct node {
    char data;
    struct node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

Node *constructNode(char data) {
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

void push(Stack *this, char data) {
    Node *newNode = constructNode(data);
    newNode->next = this->top;
    this->top = newNode;
}

char pop(Stack *this) {
    if (isEmpty(this)) {
        fprintf(stderr, "\nStack underflow!");
        return '\0';
    }
    Node *temp = this->top;
    this->top = this->top->next;
    char val = temp->data;
    free(temp);
    return val;
}

char peek(Stack *this) {
    if (isEmpty(this)) {
        fprintf(stderr, "\nStack Underflow!");
        return '\0';
    }
    return this->top->data;
}

int precedence(char op) {
    switch (op) {
        case '^':
            return 3;
        case '%':
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return INT_MIN;
    }
}

char *infixToPostfix(char infix[]) {
    char *postfix = (char *) calloc(strlen(infix + 1), sizeof(char));
    Stack *stack = constructStack();
    int j = 0;
    for (int i = 0; i < strlen(infix); i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) == '(') {
                pop(stack);
            }
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack))) {
                postfix[j++] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }
    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }
    return postfix;
}

int main() {
    char infix[MAX_SIZE];
    printf("\nEnter infix expression: ");
    scanf("%[^\n]s", infix);
    char *postfix = infixToPostfix(infix);
    printf("\nPostfix: %s", postfix);
    return 0;
}

