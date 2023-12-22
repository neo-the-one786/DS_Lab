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

int leafCountRecur(Node *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return leafCountRecur(root->left) + leafCountRecur(root->right);
}

int nodeCountRecur(Node *root) {
    if (root == NULL) {
        return 0;
    }
    return nodeCountRecur(root->left) + nodeCountRecur(root->right) + 1;
}

int depthRecur(Node *root) {
    if (root == NULL) {
        return 0;
    }
    return (int) fmax(depthRecur(root->left), depthRecur(root->right)) + 1;
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
    return (this->rear + 1) % this->cpty;
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

int leafCountIter(Node *root) {
    Node *ptr = root;
    int count = 0;
    Queue *queue = constructQueue(50);
    enqueue(queue, ptr);
    while (!isEmpty(queue)) {
        ptr = dequeue(queue);
        if (ptr->left == NULL && ptr->right == NULL) {
            count++;
        }
        if (ptr->left != NULL) {
            enqueue(queue, ptr->left);
        }
        if (ptr->right != NULL) {
            enqueue(queue, ptr->right);
        }
    }
    return count;
}

int main() {
    Node *root = constructNode(40), *leftChild = constructNode(20), *rightChild = constructNode(
            50), *leftGrandChild = constructNode(10), *rightGrandChild = constructNode(30);
    root->left = leftChild;
    root->right = rightChild;
    leftChild->left = leftGrandChild;
    leftChild->right = rightGrandChild;
    printf("\nLeaf: %d", leafCountRecur(root));
    printf("\nLeaf: %d", leafCountIter(root));
    printf("\nNode: %d", nodeCountRecur(root));
    printf("\nDepth: %d", depthRecur(root));
}