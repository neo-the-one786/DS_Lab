// 8.2 Write a menu driven program to implement priority queue operations such as Enqueue, Dequeue,
// Traverse using linked list.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data, prty;
    struct Node *next;
} Node;

typedef struct {
    Node *front, *rear;
} PriorityQueue;

Node *constructNode(int data, int prty) {
    Node *this = (Node *) malloc(sizeof(Node));
    this->data = data;
    this->prty = prty;
    this->next = NULL;
    return this;
}

PriorityQueue *constructPQ() {
    PriorityQueue *this = (PriorityQueue *) malloc(sizeof(PriorityQueue));
    this->front = NULL;
    this->rear = NULL;
    return this;
}

bool isEmpty(PriorityQueue *this) {
    return this->front == NULL;
}

void enqueue(PriorityQueue *this, int data, int prty) {
    Node *newNode = constructNode(data, prty);
    if (isEmpty(this)) {
        this->front = this->rear = newNode;
        return;
    }
    if (prty < this->front->prty) {
        newNode->next = this->front;
        this->front = newNode;
        return;
    }
    Node *ptr = this->front;
    while (ptr->next != NULL && prty > ptr->next->prty) {
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
    if (newNode->next == NULL) {
        this->rear = newNode;
    }
}

int dequeue(PriorityQueue *this) {
    if (isEmpty(this)) {
        fprintf(stderr, "\nPQ Empty!");
        return INT_MIN;
    }
    Node *temp = this->front;
    this->front = this->front->next;
    int data = temp->data;
    free(temp);
    return data;
}

void print(PriorityQueue *this) {
    printf("\n[");
    Node *ptr = this->front;
    while (ptr != NULL) {
        if (ptr->next != NULL) {
            printf("%d = %d, ", ptr->data, ptr->prty);
        } else {
            printf("%d = %d", ptr->data, ptr->prty);
        }
        ptr = ptr->next;
    }
    printf("]\n");
}

int main() {
    int opt, data, prty;
    PriorityQueue *pq = constructPQ();
    do {
        printf("\nMain Menu\nEnter 1 to Enqueue\nEnter 2 to Dequeue\nEnter 3 to IsEmpty\nEnter 4 to Traverse\nEnter 5 to Exit");
        printf("\nEnter option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                printf("\nEnter data & priority: ");
                scanf("%d %d", &data, &prty);
                enqueue(pq, data, prty);
                break;
            case 2:
                printf("\nDequeued %d", dequeue(pq));
                break;
            case 3:
                if (isEmpty(pq)) {
                    printf("\nTrue");
                } else {
                    printf("\nFalse");
                }
                break;
            case 4:
                print(pq);
                break;
            case 5:
                while (!isEmpty(pq)) {
                    dequeue(pq);
                }
                free(pq);
                exit(0);
            default:
                fprintf(stderr, "\nInvalid input!");
                break;
        }
    } while (opt != 5);
    return 0;
}