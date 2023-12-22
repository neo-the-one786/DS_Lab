//10.3 In addition to 10.1, display BFS traversal sequence of the undirected graph.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Graph {
    int vtx, **mtx;
} Graph;

Graph *construct(int vtx) {
    Graph *this = (Graph *) malloc(sizeof(Graph));
    this->vtx = vtx;
    this->mtx = (int **) malloc((this->vtx * sizeof(int *)));
    for (int i = 0; i < this->vtx; i++) {
        this->mtx[i] = (int *) calloc(this->vtx, sizeof(int));
    }
    return this;
}

void addEdge(Graph *this, int src, int dest) {
    if (this == NULL || src < 0 || src > this->vtx || dest < 0 || dest >= this->vtx) {
        fprintf(stderr, "Index Out Of Bounds!");
        return;
    }
    this->mtx[src][dest] = this->mtx[dest][src] = 1;
}

#define MAX_VAL 50

typedef struct {
    int cpty, front, rear, *arr;
} Queue;

Queue *constructQueue(int cpty) {
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

void bfs(Graph *this, int src) {
    printf("\n");
    Queue *queue = constructQueue(MAX_VAL);
    bool *isVisited = (bool *) calloc(this->vtx, sizeof(bool));
    enqueue(queue, src);
    isVisited[src] = true;
    while (!isEmpty(queue)) {
        int currVtx = dequeue(queue);
        printf("%d -> ", currVtx);
        for (int i = 0; i < this->vtx; i++) {
            if (this->mtx[currVtx][i] == 1 && !isVisited[i]) {
                enqueue(queue, i);
                isVisited[i] = true;
            }
        }
    }
    free(queue->arr);
    free(queue);
}

int main() {
    int vtx, edge, src, dest;
    printf("\nEnter no of vtx: ");
    scanf("%d", &vtx);
    Graph *graph = construct(vtx);
    printf("\nEnter no of edges: ");
    scanf("%d", &edge);
    printf("\nEnter edges: ");
    for (int i = 0; i < edge; i++) {
        scanf("%d%d", &src, &dest);
        addEdge(graph, src, dest);
    }
    printf("\nEnter source vertex: ");
    scanf("%d", &src);
    printf("\nBFS Traversal:\n");
    bfs(graph, src);
}