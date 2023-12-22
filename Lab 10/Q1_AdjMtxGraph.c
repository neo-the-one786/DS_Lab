// 10.1 WAP to create an un-directed graph using Adjacency Matrix Method and display the degree of each
// vertex.

#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int vtx, **mtx;
} Graph;

Graph *construct(int vtx) {
    Graph *this = (Graph *) malloc(sizeof(Graph));
    this->vtx = vtx;
    this->mtx = (int **) malloc(this->vtx * sizeof(int *));
    for (int i = 0; i < this->vtx; i++) {
        this->mtx[i] = (int *) calloc(this->vtx, sizeof(int));
    }
    return this;
}

void addEdge(Graph *this, int src, int dest) {
    if (src < 0 || dest < 0 || src >= this->vtx || dest >= this->vtx) {
        fprintf(stderr, "\nIndex Out Of Bounds!");
        return;
    }
    this->mtx[src][dest] = this->mtx[dest][src] = 1;
}

void displayDegree(Graph *this) {
    for (int i = 0; i < this->vtx; i++) {
        int degree = 0;
        for (int j = 0; j < this->vtx; j++) {
            if (this->mtx[i][j] == 1) {
                degree++;
            }
        }
        printf("\n%d\t%d", i + 1, degree);
    }
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
    printf("\nVextex\tDegree\n");
    displayDegree(graph);
}