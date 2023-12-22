// 8.1 Write a menu driven program to implement Deques (both Inputrestricted and output-restricted) and
// performed operations such as Enqueue, Dequeue, Peek, IsEmpty, IsFull using static array.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int cpty, *arr, front, rear;
} Deque;

Deque *construct(int cpty) {
    Deque *this = (Deque *) malloc(sizeof(Deque));
    this->cpty = cpty;
    this->front = -1;
    this->rear = -1;
    this->arr = (int *) calloc(this->cpty, sizeof(int));
    return this;
}

bool isEmpty(Deque *this) {
    return this->front == -1;
}

bool isFull(Deque *this) {
    return (this->rear + 1) % this->cpty == this->front;
}

void prepend(Deque *this, int data) {
    if (isFull(this)) {
        fprintf(stderr, "\nDeque Full!");;
        return;
    }
    if (isEmpty(this)) {
        this->front = this->rear = 0;
    } else {
        this->front = (this->front - 1 + this->cpty) % this->cpty;
    }
    this->arr[this->front] = data;
}

void append(Deque *this, int data) {
    if (isFull(this)) {
        fprintf(stderr, "\nDeque Full!");;
        return;
    }
    if (isEmpty(this)) {
        this->front = 0;
    }
    this->rear = (this->rear + 1) % this->cpty;
    this->arr[this->rear] = data;
}

int poll(Deque *this) {
    if (isEmpty(this)) {
        fprintf(stderr, "\nDeque  Empty!");
        return INT_MIN;
    }
    int data = this->arr[this->front];
    if (this->front == this->rear) {
        this->front = this->rear = -1;
    } else {
        this->front = (this->front + 1) % this->cpty;
    }
    return data;
}

int shift(Deque *this) {
    if (isEmpty(this)) {
        fprintf(stderr, "\nDeque  Empty!");
        return INT_MIN;
    }
    int data = this->arr[this->rear];
    if (this->front == this->rear) {
        this->front = this->rear = -1;
    } else {
        this->rear = (this->rear - 1 + this->cpty) % this->cpty;
    }
    return data;
}

void print(Deque *this) {
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
    printf("Enter deque capacity: ");
    scanf("%d", &cpty);
    Deque *deque = construct(cpty);
    do {
        printf("\nMain Menu\nEnter 1 to insert at left\nEnter 2 to insert at right\nEnter 3 to delete from left\nEnter 4 to delete from right\nEnter 5 to IsEmpty\nEnter 6 to IsFull\nEnter 7 to Traverse\nEnter 8 to Exit");
        printf("\nEnter option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                printf("\nEnter data: ");
                scanf("%d", &data);
                prepend(deque, data);
                break;
            case 2:
                printf("\nEnter data: ");
                scanf("%d", &data);
                append(deque, data);
                break;
            case 3:
                printf("\nPolled %d", poll(deque));
                break;
            case 4:
                printf("\nShifted %d", shift(deque));
                break;
            case 5:
                if (isEmpty(deque)) {
                    printf("\nTrue");
                } else {
                    printf("\nFalse");
                }
                break;
            case 6:
                if (isFull(deque)) {
                    printf("\nTrue");
                } else {
                    printf("\nFalse");
                }
                break;
            case 7:
                print(deque);
                break;
            case 8:
                free(deque->arr);
                free(deque);
                exit(0);
            default:
                printf("\nInvalid input!");
                break;
        }
    } while (opt != 8);
    return 0;
}