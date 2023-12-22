// 7.2 Write a menu driven program to implement linear queue operations such as Enqueue, Dequeue,
// IsEmpty, Traverse using single linked list.

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
    return this->front == -1;
}

bool isFull(Queue *this) {
    return (this->rear + 1) % this->cpty == this->front;
}

void enqueue(Queue *this, int data) {
    if (isFull(this)) {
        fprintf(stderr, "\nQueue Full!");
        return;
    }
    if (isEmpty(this)) {
        this->front = 0;
    }
    this->rear = (this->rear + 1) % this->cpty;
    this->arr[this->rear] = data;
}

int dequeue(Queue *this) {
    if (isEmpty(this)) {
        fprintf(stderr, "\nQueue Empty!");
        return INT_MIN;
    }
    int data = this->arr[this->front];
    if (isEmpty(this)) {
        this->front = this->rear = -1;
    } else {
        this->front = (this->front + 1) % this->cpty;
    }
    return data;
}

void traverse(Queue *this) {
    printf("\n[");
    int i = this->front;
    do {
        if (i != this->rear) {
            printf("%d, ", this->arr[i]);
        } else {
            printf("%d", this->arr[i]);
        }
        i = (i + 1) % this->cpty;
    } while (i != (this->rear + 1) % this->cpty);
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