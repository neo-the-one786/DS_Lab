#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *constructNode(int data) {
    Node *this = (Node *) malloc(sizeof(Node));
    this->data = data;
    this->left = NULL;
    this->right = NULL;
    return this;
}

typedef struct Queue {
    int front, rear, cpty;
    Node **arr;
} Queue;

Queue *constructQueue(int cpty) {
    Queue *this = (Queue *) malloc(sizeof(Queue));
    this->cpty = cpty;
    this->front = -1;
    this->rear = -1;
    this->arr = (Node **) malloc(this->cpty * sizeof(Node *));
    return this;
}

bool isEmpty(Queue *this) {
    return this->front == -1;
}

bool isFull(Queue *this) {
    return (this->rear + 1) % this->cpty == this->front;
}

void enqueue(Queue *this, Node *newNode) {
    if (isFull(this)) {
        return;
    }
    if (isEmpty(this)) {
        this->front = 0;
    }
    this->rear = (this->rear + 1) % this->cpty;
    this->arr[this->rear] = newNode;
}

Node *dequeue(Queue *this) {
    if (isEmpty(this)) {
        return NULL;
    }
    Node *op = this->arr[this->front];
    if (this->front == this->rear) {
        this->front = this->rear = -1;
    } else {
        this->front = (this->front + 1) % this->cpty;
    }
    return op;
}

void levelOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    Node *ptr = root;
    Queue *queue = constructQueue(50);
    enqueue(queue, ptr);
    while (!isEmpty(queue)) {
        ptr = dequeue(queue);
        printf("%d ", ptr->data);
        if (ptr->left != NULL) {
            enqueue(queue, ptr->left);
        }
        if (ptr->right != NULL) {
            enqueue(queue, ptr->right);
        }
    }
}

int main() {
    Node *root = constructNode(40), *leftChild = constructNode(20), *rightChild = constructNode(
            50), *leftGrandChild = constructNode(10), *rightGrandChild = constructNode(30);
    root->left = leftChild;
    root->right = rightChild;
    leftChild->left = leftGrandChild;
    leftChild->right = rightGrandChild;
    levelOrder(root);
    return 0;
}