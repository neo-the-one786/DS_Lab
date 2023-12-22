// 7.1 Write a menu driven program to create a linear queue using array and perform Enqueue, Dequeue,
// Traverse, IsEmpty, IsFull operations.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int cpty, front, rear, *arr;
} Queue;

Queue *construct(int cpty) {
    Queue *this = (Queue *) malloc(sizeof(Queue));
    this->cpty = cpty;
    this->arr = (int *) calloc(this->cpty, sizeof(int));
    this->front = -1;
    this->rear = -1;
    return this;
}

bool isEmpty(Queue *this) {
    return this->front == -1 || this->front == this->rear + 1;
}

bool isFull(Queue *this) {
    return this->rear == this->cpty - 1;
}

void enqueue(Queue *this, int data) {
    if (isFull(this)) {
        fprintf(stderr, "\nQueue Full!");
        return;
    }
    if (this->front == -1) {
        this->front = 0;
    }
    this->arr[++this->rear] = data;
}

int dequeue(Queue *this) {
    if (isEmpty(this)) {
        fprintf(stderr, "\nQueue Empty!");
        return INT_MIN;
    }
    return this->arr[this->front++];
}

void traverse(Queue *this) {
    printf("\n[");
    for (int i = this->front; i <= this->rear; i++) {
        if (i != this->rear) {
            printf("%d, ", this->arr[i]);
        } else {
            printf("%d", this->arr[i]);
        }
    }
    printf("]\n");
}

int main() {
    int cpty, opt, data;
    printf("Enter queue capacity: ");
    scanf("%d", &cpty);
    Queue *queue = construct(cpty);
    do {
        printf("\nMain Menu\nEnter 1 to Enqueue\nEnter 2 to Dequeue\nEnter 3 to IsEmpty\nEnter 4 to IsFull\nEnter 5 to Traverse\nEnter 6 to Exit");
        printf("\nEnter option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                printf("\nEnter data: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                printf("\n%d dequeued", dequeue(queue));
                break;
            case 3:
                if (isEmpty(queue)) {
                    printf("\nTrue");
                } else {
                    printf("\nFalse");
                }
                break;
            case 4:
                if (isFull(queue)) {
                    printf("\nTrue");
                } else {
                    printf("\nFalse");
                }
                break;
            case 5:
                traverse(queue);
                break;
            case 6:
                free(queue->arr);
                free(queue);
                exit(0);
            default:
                printf("\nInvalid input!");
                break;
        }
    } while (opt != 6);
    return 0;
}