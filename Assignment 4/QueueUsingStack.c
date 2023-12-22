#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    int capacity;
    int *array;
} Stack;

Stack *createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

bool isStackEmpty(Stack *stack) {
    return stack->top == -1;
}

bool isStackFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack *stack, int data) {
    if (isStackFull(stack)) {
        fprintf(stderr, "Stack Overflow!\n");
        return;
    }
    stack->array[++stack->top] = data;
}

int pop(Stack *stack) {
    if (isStackEmpty(stack)) {
        fprintf(stderr, "Stack Underflow!\n");
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

int peek(Stack *stack) {
    if (isStackEmpty(stack)) {
        fprintf(stderr, "Stack is empty!\n");
        return INT_MIN;
    }
    return stack->array[stack->top];
}

typedef struct {
    Stack *s1;
    Stack *s2;
} Queue;

Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->s1 = createStack(capacity);
    queue->s2 = createStack(capacity);
    return queue;
}

bool isQueueEmpty(Queue *queue) {
    return isStackEmpty(queue->s1) && isStackEmpty(queue->s2);
}

void enqueue(Queue *queue, int data) {
    if (isStackFull(queue->s1)) {
        fprintf(stderr, "Queue Overflow!\n");
        return;
    }
    while (!isStackEmpty(queue->s1)) {
        push(queue->s2, pop(queue->s1));
    }
    push(queue->s1, data);
    while (!isStackEmpty(queue->s2)) {
        push(queue->s1, pop(queue->s2));
    }
}

int dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        fprintf(stderr, "Queue Underflow!\n");
        return INT_MIN;
    }
    return pop(queue->s1);
}

int front(Queue *queue) {
    if (isQueueEmpty(queue)) {
        fprintf(stderr, "Queue is empty!\n");
        return INT_MIN;
    }
    return peek(queue->s1);
}

int main() {
    Queue *queue = createQueue(MAX_SIZE);
    int opt, data;
    do {
        printf("\nEnter 1 to enqueue\nEnter 2 to dequeue\nEnter 3 to peek\nEnter 4 to exit");
        printf("\nEnter your choice: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1: {
                printf("\nEnter data to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            }
            case 2: {
                printf("\n%d dequeued", dequeue(queue));
                break;
            }
            case 3: {
                printf("\n%d peeked", front(queue));
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                fprintf(stderr, "Invalid Input!");
            }
        }
    } while (opt != 4);
    return 0;
}
