//10.2 In addition to 10.1, display DFS traversal sequence of the undirected graph.

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

void dfsHelper(Graph *this, int src, bool isVisited[]) {
    isVisited[src] = true;
    printf("%d -> ", src);
    for (int i = 0; i < this->vtx; i++) {
        if (this->mtx[src][i] == 1 && !isVisited[i]) {
            dfsHelper(this, i, isVisited);
        }
    }
}

void dfsRecur(Graph *this, int src) {
    bool *isVisited = (bool *) calloc(this->vtx, sizeof(bool));
    printf("\n");
    dfsHelper(this, src, isVisited);
    free(isVisited);
}

#define MAX_VAL 50

typedef struct {
    int top, cpty, *arr;
} Stack;

Stack *constructStack(int cpty) {
    Stack *this = (Stack *) malloc(sizeof(Stack));
    this->cpty = cpty;
    this->arr = (int *) malloc(this->cpty * sizeof(int));
    this->top = -1;
    return this;
}

bool isEmpty(Stack *this) {
    return this->top == -1;
}

bool isFull(Stack *this) {
    return this->top == this->cpty - 1;
}

void push(Stack *this, int data) {
    if (isFull(this)) {
        return;
    }
    this->arr[++this->top] = data;
}

int pop(Stack *this) {
    if (isEmpty(this)) {
        return INT_MIN;
    }
    return this->arr[this->top--];
}

void dfsIter(Graph *this, int src) {
    printf("\n");
    Stack *stack = constructStack(MAX_VAL);
    bool *isVisited = (bool *) calloc(this->vtx, sizeof(bool));
    push(stack, src);
    isVisited[src] = true;
    while (!isEmpty(stack)) {
        int currVtx = pop(stack);
        printf("%d -> ", currVtx);
        for (int i = 0; i < this->vtx; i++) {
            if (this->mtx[currVtx][i] == 1 && !isVisited[i]) {
                push(stack, i);
                isVisited[i] = true;
            }
        }
    }
    free(stack->arr);
    free(stack);
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
    printf("\nDFS Traversal:\n");
    dfsRecur(graph, src);
    dfsIter(graph, src);
}