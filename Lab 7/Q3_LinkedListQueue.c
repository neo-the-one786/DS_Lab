// 7.3 Write a menu driven program to implement circular queue operations such as Enqueue, Dequeue,
//Traverse, IsEmpty, IsFull using array.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front, *rear;
} Queue;

Node *constructNode(int data) {
    Node *this = (Node *) malloc(sizeof(Node));
    this->data = data;
    this->next = NULL;
    return this;
}

Queue *constructQueue() {
    Queue *this = (Queue *) malloc(sizeof(Queue));
    this->front = NULL;
    this->rear = NULL;
    return this;
}

bool isEmpty(Queue *this) {
    return this->front == NULL;
}

void enqueue(Queue *this, int data) {
    Node *newNode = constructNode(data);
    if (isEmpty(this)) {
        this->front = this->rear = newNode;
        return;
    }
    this->rear->next = newNode;
    this->rear = newNode;
}

int dequeue(Queue *this) {
    if (isEmpty(this)) {
        fprintf(stderr, "\nQueue Empty!");
        return INT_MIN;
    }
    Node *temp = this->front;
    int data = temp->data;
    if (this->front == this->rear) {
        this->front = this->rear = NULL;
    } else {
        this->front = this->front->next;
    }
    return data;
}

void traverse(Queue *this) {
    printf("\n[");
    Node *ptr = this->front;
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
    Queue *queue = constructQueue();
    do {
        printf("\nMain Menu\nEnter 1 to Enqueue\nEnter 2 to Dequeue\nEnter 3 to IsEmpty\nEnter 4 to Traverse\nEnter 5 to Exit");
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
                traverse(queue);
                break;
            case 5:
                while (!isEmpty(queue)) {
                    dequeue(queue);
                }
                free(queue);
                exit(0);
            default:
                printf("\nInvalid input!");
                break;
        }
    } while (opt != 5);
    return 0;
}