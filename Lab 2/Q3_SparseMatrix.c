// 2.3 WAP to represent a given sparse matrix in 3-tuple format using 2-D array.

#include <stdio.h>
#include <stdlib.h>

int **sprsMtxToTrip(int **sprsMtx, int m, int n) {
    int nZ = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (sprsMtx[i][j] != 0) {
                nZ++;
            }
        }
    }
    int **triplet = (int **) malloc((nZ + 1) * sizeof(int *));
    for (int i = 0; i <= nZ; i++) {
        triplet[i] = (int *) calloc(3, sizeof(int));
    }
    triplet[0][0] = m;
    triplet[0][1] = n;
    triplet[0][2] = nZ;
    int k = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (sprsMtx[i][j] != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = sprsMtx[i][j];
                k++;
            }
        }
    }
    return triplet;
}

int main() {
    int m, n;
    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &m, &n);
    int **sprsMtx = (int **) malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        sprsMtx[i] = (int *) calloc(m, sizeof(int));
    }
    printf("\nEnter sparse matrix elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &sprsMtx[i][j]);
        }
    }
    int **triplet = sprsMtxToTrip(sprsMtx, m, n);
    printf("\nTriplet: \n");
    for (int i = 0; i <= triplet[0][2]; i++) {
        printf("%d %d %d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }
    for (int i = 0; i < m; i++) {
        free(sprsMtx[i]);
    }
    free(sprsMtx);
    for (int i = 0; i <= triplet[0][2]; i++) {
        free(triplet[i]);
    }
    free(triplet);
    return 0;
}
