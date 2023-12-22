#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int i, j, elem;
    struct Node *next;
} Node;

typedef struct Header {
    int m, n, nZ;
    struct Node *next;
} Header;

Node *construct(int i, int j, int elem) {
    Node *this = (Node *) malloc(sizeof(Node));
    this->i = i;
    this->j = j;
    this->elem = elem;
    this->next = NULL;
    return this;
}

void peechheSeGhusaao(Header **head, int i, int j, int elem) {
    Node *newNode = construct(i, j, elem);
    if ((*head)->next == NULL) {
        (*head)->next = newNode;
        return;
    }
    Node *ptr = (*head)->next;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

void dikhaao(Header *head) {
    printf("\n%d %d %d", head->m, head->n, head->nZ);
    Node *ptr = head->next;
    while (ptr != NULL) {
        printf("\n%d %d %d", ptr->i, ptr->j, ptr->elem);
        ptr = ptr->next;
    }
}

int main() {
    int m, n, nZ = 0;
    printf("\nEnter no of row and columns: ");
    scanf("%d%d", &m, &n);
    int **mtx = (int **) malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        mtx[i] = (int *) malloc(n * sizeof(int));
    }
    Header *head = (Header *) malloc(sizeof(Header));
    head->m = m;
    head->n = n;
    head->nZ = nZ;
    head->next = NULL;
    printf("\nEnter sparse matrix: ");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mtx[i][j]);
            if (mtx[i][j] != 0) {
                head->nZ++;
                peechheSeGhusaao(&head, i, j, mtx[i][j]);
            }
        }
    }
    dikhaao(head);
    return 0;
}