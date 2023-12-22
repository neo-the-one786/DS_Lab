// 3.1 WAP to perform transpose of a given sparse matrix in 3-tuple format.

#include <stdio.h>
#include <stdlib.h>

int **transpose(int **trip) {
    int m = trip[0][0], n = trip[0][1], nZ = trip[0][2];
    int **trps = (int **) malloc((nZ + 1) * sizeof(int *));
    for (int i = 0; i <= nZ; i++) {
        trps[i] = (int *) calloc(3, sizeof(int));
    }
    trps[0][0] = n;
    trps[0][1] = m;
    trps[0][2] = nZ;
    int k = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= nZ; j++) {
            if (i == trip[j][1]) {
                trps[k][0] = trip[i][1];
                trps[k][1] = trip[i][0];
                trps[k][2] = trip[i][2];
                k++;
            }
        }
    }
    return trps;
}

int main() {
    int m, n, nZ;
    printf("\nEnter sparse matrix in triplet form: ");
    scanf("%d %d %d", &m, &n, &nZ);
    int **trip = (int **) malloc((nZ + 1) * sizeof(int *));
    for (int i = 0; i <= nZ; i++) {
        trip[i] = (int *) malloc(3 * sizeof(int));
    }
    trip[0][0] = m;
    trip[0][1] = n;
    trip[0][2] = nZ;
    for (int i = 1; i <= nZ; i++) {
        scanf("%d %d %d", &trip[i][0], &trip[i][1], &trip[i][2]);
    }
    int **trps = transpose(trip);
    for (int i = 0; i <= nZ; i++) {
        printf("\n%d %d %d", trps[i][0], trps[i][1], trps[i][2]);
    }
    return 0;
}