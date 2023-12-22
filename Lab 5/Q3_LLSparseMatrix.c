// 5.3 Write a program to represent the given sparse matrix using header single linked list and
// display it.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int i, j, elem;
    struct Node *next;
} Node;

Node *construct(int i, int j, int elem) {
    Node *this = (Node *) malloc(sizeof(Node));
    this->i = i;
    this->j = j;
    this->elem = elem;
    this->next = NULL;
    return this;
}

void append(Node **this, int i, int j, int elem) {
    Node *newNode = construct(i, j, elem);
    if (*this == NULL) {
        *this = newNode;
        return;
    }
    Node *ptr = *this;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

Node *sprsMtxToTrip(int **sprsMtx, int m, int n) {
    Node *triplet = NULL;
    int nZ = 0;
    append(&triplet, m, n, nZ);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (sprsMtx[i][j] != 0) {
                nZ++;
                append(&triplet, i, j, sprsMtx[i][j]);
            }
        }
    }
    triplet->elem = nZ;
    return triplet;
}

void display(Node *triplet) {
    Node *ptr = triplet;
    while (ptr != NULL) {
        printf("\n%d %d %d", ptr->i, ptr->j, ptr->elem);
        ptr = ptr->next;
    }
}

int main() {
    int m, n;
    printf("\nEnter sparse matrix size: ");
    scanf("%d%d", &m, &n);
    int **sprsMtx = (int **) malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        sprsMtx[i] = (int *) calloc(n, sizeof(int));
    }
    printf("\nEnter sparse matrix elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &sprsMtx[i][j]);
        }
    }
    Node *triplet = sprsMtxToTrip(sprsMtx, m, n);
    printf("\nTriplet:\n");
    display(triplet);
    return 0;
}
