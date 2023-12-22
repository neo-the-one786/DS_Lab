// 2.2 Write a program to perform the following operations on a given square matrix using functions:
// i. Find the no.of nonzero elements
// ii. Display upper triangular matrix
// iii. Display the elements of just above and below the main diagonal

#include <stdio.h>
#include <stdlib.h>

int nonZeroCount(int **mtx, int m, int n) {
    int nonZero = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mtx[i][j] != 0) {
                nonZero++;
            }
        }
    }
    return nonZero;
}

void upTriMtx(int **mtx, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i) {
                printf("%d ", mtx[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void mtxSansMainDiag(int **mtx, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                printf("  ");
            } else {
                printf("%d ", mtx[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int m, n;
    printf("\nEnter number of rows and columns: ");
    scanf("%d %d", &m, &n);
    int **mtx = (int **) malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        mtx[i] = (int *) calloc(n, sizeof(int));
    }
    printf("\nEnter elements: ");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mtx[i][j]);
        }
    }
    int opt;
    do {
        printf("\nMenu:\nEnter 1 for non zero count\nEnter 2 for upper triangular matrix\nEnter 3 for matrix  without main diagonal\nEnter 4 for exit");
        printf("\nEnter your option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1: {
                printf("\nNo of non zero elements: %d", nonZeroCount(mtx, m, n));
                break;
            }
            case 2: {
                printf("\nUpper triangular matrix: \n");
                upTriMtx(mtx, m, n);
                break;
            }
            case 3: {
                printf("\nMatrix sans main diagonal: \n");
                mtxSansMainDiag(mtx, m, n);
                break;
            }
            case 4: {
                free(mtx);
                exit(0);
            }
            default: {
                printf("\nInvalid input");
            }
        }
    } while (opt != 4);
    return 0;
}