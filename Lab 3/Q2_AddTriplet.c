// 3.2 WAP to perform addition of two given sparse matrix in 3–tuple format.

#include <stdio.h>
#include <stdlib.h>

int **add(int **trip1, int **trip2) {
    int nZ1 = trip1[0][2], nZ2 = trip2[0][2], m1 = trip1[0][0], n1 = trip1[0][1];
    int **sum = (int **) malloc((nZ1 + nZ2 + 1) * sizeof(int *));
    for (int i = 0; i <= nZ1 + nZ2; i++) {
        sum[i] = (int *) calloc(3, sizeof(int));
    }
    sum[0][0] = m1;
    sum[0][1] = n1;
    int i = 1, j = 1, k = 1;
    while (i <= nZ1 && j <= nZ2) {
        if (trip1[i][0] < trip2[j][0] || (trip1[i][0] == trip2[j][0] && trip1[i][1] < trip2[j][1])) {
            sum[k][0] = trip1[i][0];
            sum[k][1] = trip1[i][1];
            sum[k][2] = trip1[i][2];
            i++;
        } else if (trip1[i][0] > trip2[j][0] || (trip1[i][0] == trip2[j][0] && trip1[i][1] > trip2[j][1])) {
            sum[k][0] = trip2[j][0];
            sum[k][1] = trip2[j][1];
            sum[k][2] = trip2[j][2];
            j++;
        } else {
            sum[k][0] = trip2[j][0];
            sum[k][1] = trip2[j][1];
            sum[k][2] = trip1[i][2] + trip2[j][2];
            i++;
            j++;
        }
        k++;
    }
    while (i <= nZ1) {
        sum[k][0] = trip1[i][0];
        sum[k][1] = trip1[i][1];
        sum[k][2] = trip1[i][2];
        i++;
        k++;
    }
    while (j <= nZ2) {
        sum[k][0] = trip2[j][0];
        sum[k][1] = trip2[j][1];
        sum[k][2] = trip2[j][2];
        j++;
        k++;
    }
    sum[0][2] = k - 1;
    sum = (int **) realloc(sum, k * sizeof(int *));
    return sum;
}

int main() {
    int m1, n1, nZ1, m2, n2, nZ2;
    printf("\nEnter 1st triplet: ");
    scanf("%d %d %d", &m1, &n1, &nZ1);
    int **trip1 = (int **) malloc((nZ1 + 1) * sizeof(int *));
    for (int i = 0; i <= nZ1; i++) {
        trip1[i] = (int *) malloc(3 * sizeof(int));
    }
    trip1[0][0] = m1;
    trip1[0][1] = n1;
    trip1[0][2] = nZ1;
    for (int i = 1; i <= nZ1; i++) {
        scanf("%d %d %d", &trip1[i][0], &trip1[i][1], &trip1[i][2]);
    }
    printf("\nEnter 2nd triplet: ");
    scanf("%d %d %d", &m2, &n2, &nZ2);
    if (m1 != m2 || n1 != n2) {
        printf("\nOrder does NOT match!");
        return 0;
    }
    int **trip2 = (int **) malloc((nZ2 + 1) * sizeof(int *));
    for (int i = 0; i <= nZ2; i++) {
        trip2[i] = (int *) malloc(3 * sizeof(int));
    }
    trip2[0][0] = m2;
    trip2[0][1] = n2;
    trip2[0][2] = nZ2;
    for (int i = 1; i <= nZ2; i++) {
        scanf("%d %d %d", &trip2[i][0], &trip2[i][1], &trip2[i][2]);
    }
    int **sum = add(trip1, trip2);
    printf("\nSum: ");
    int nZS = sum[0][2];
    for (int i = 0; i <= nZS; i++) {
        printf("\n%d %d %d", sum[i][0], sum[i][1], sum[i][2]);
    }
    for (int i = 0; i <= nZ1; i++) {
        free(trip1[i]);
    }
    free(trip1);
    for (int i = 0; i <= nZ2; i++) {
        free(trip2[i]);
    }
    free(trip2);
    for (int i = 0; i < nZ1 + nZ2 + 1; i++) {
        free(sum[i]);
    }
    free(sum);
    return 0;
}