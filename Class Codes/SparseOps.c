#include <stdio.h>
#include <stdlib.h>

int **add(int **trip1, int **trip2) {
    int m1 = trip1[0][0], n1 = trip1[0][1], nonZero1 = trip1[0][2], nonZero2 = trip2[0][2];
    int **sum = (int **) malloc((m1 * n1 + 1) * sizeof(int *));
    for (int i = 0; i <= m1 * n1; i++) {
        sum[i] = (int *) malloc(3 * sizeof(int));
    }
    sum[0][0] = m1;
    sum[0][1] = n1;
    int i = 1, j = 1, k = 1;
    while (i <= nonZero1 && j <= nonZero2) {
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
            sum[k][0] = trip1[i][0];
            sum[k][1] = trip1[i][1];
            sum[k][2] = trip1[i][2] + trip2[j][0];
            i++;
            j++;
        }
        k++;
    }
    while (i <= nonZero1) {
        sum[k][0] = trip1[i][0];
        sum[k][1] = trip1[i][1];
        sum[k][2] = trip1[i][2];
        i++;
        k++;
    }
    while (j <= nonZero2) {
        sum[k][0] = -trip2[j][0];
        sum[k][1] = -trip2[j][1];
        sum[k][2] = -trip2[j][2];
        j++;
        k++;
    }
    sum[0][2] = k - 1;
    sum = (int **) realloc(sum, k * sizeof(int *));
    for (int idx = 0; idx <= k; idx++) {
        sum[idx] = (int *) realloc(sum[idx], 3 * sizeof(int));
    }
    return sum;
}

int **sub(int **trip1, int **trip2) {
    int m1 = trip1[0][0], n1 = trip1[0][1], nonZero1 = trip1[0][2], nonZero2 = trip2[0][2];
    int **diff = (int **) malloc((m1 * n1 + 1) * sizeof(int *));
    for (int i = 0; i <= m1 * n1; i++) {
        diff[i] = (int *) malloc(3 * sizeof(int));
    }
    diff[0][0] = m1;
    diff[0][1] = n1;
    int i = 1, j = 1, k = 1;
    while (i <= nonZero1 && j <= nonZero2) {
        if (trip1[i][0] < trip2[j][0] || (trip1[i][0] == trip2[j][0] && trip1[i][1] < trip2[j][1])) {
            diff[k][0] = trip1[i][0];
            diff[k][1] = trip1[i][1];
            diff[k][2] = trip1[i][2];
            i++;
        } else if (trip1[i][0] > trip2[j][0] || (trip1[i][0] == trip2[j][0] && trip1[i][1] > trip2[j][1])) {
            diff[k][0] = -trip2[j][0];
            diff[k][1] = -trip2[j][1];
            diff[k][2] = -trip2[j][2];
            j++;
        } else {
            diff[k][0] = trip1[i][0];
            diff[k][1] = trip1[i][1];
            diff[k][2] = trip1[i][2] - trip2[j][0];
            i++;
            j++;
        }
        k++;
    }
    while (i <= nonZero1) {
        diff[k][0] = trip1[i][0];
        diff[k][1] = trip1[i][1];
        diff[k][2] = trip1[i][2];
        i++;
        k++;
    }
    while (j <= nonZero2) {
        diff[k][0] = -trip2[j][0];
        diff[k][1] = -trip2[j][1];
        diff[k][2] = -trip2[j][2];
        j++;
        k++;
    }
    diff[0][2] = k - 1;
    diff = (int **) realloc(diff, k * sizeof(int *));
    for (int idx = 0; idx <= k; idx++) {
        diff[idx] = (int *) realloc(diff[idx], 3 * sizeof(int));
    }
    return diff;
}

int lSearch(int **mtx, int row, int col, int len) {
    for (int i = 0; i < len; i++) {
        if (mtx[i][0] == row && mtx[i][1] == col) {
            return i;
        }
    }
    return -1;
}

int **mul(int **trip1, int **trip2) {
    int m1 = trip1[0][0], n2 = trip2[0][1], nonZero1 = trip1[0][2], nonZero2 = trip2[0][2];
    int **prod = (int **) malloc((m1 * n2 + 1) * sizeof(int *));
    for (int i = 0; i <= m1 * n2; i++) {
        prod[i] = (int *) malloc(3 * sizeof(int));
    }
    prod[0][0] = m1;
    prod[0][1] = n2;
    int k = 1;
    for (int i = 1; i <= nonZero1; i++) {
        for (int j = 1; j <= nonZero2; j++) {
            if (trip1[i][1] == trip2[j][0]) {
                int val = trip1[i][2] * trip2[j][2];
                int row = trip1[i][0], col = trip2[j][1];
                int pos = lSearch(prod, row, col, k - 1);
                if (pos == -1) {
                    prod[k][0] = row;
                    prod[k][1] = col;
                    prod[k][2] = val;
                    k++;
                } else {
                    prod[pos][2] += val;
                }
            }
        }
    }
    prod[0][2] = k - 1;
    prod = (int **) realloc(prod, k * sizeof(int *));
    for (int i = 0; i <= k; i++) {
        prod[i] = (int *) realloc(prod[i], 3 * sizeof(int));
    }
    return prod;
}

int main() {
    int m1, n1, nonZero1, m2, n2, nonZero2;
    printf("\nEnter 1st triplet: ");
    scanf("%d %d %d", &m1, &n1, &nonZero1);
    int **trip1 = (int **) malloc((nonZero1 + 1) * sizeof(int *));
    for (int i = 0; i <= nonZero1; i++) {
        trip1[i] = (int *) malloc(3 * sizeof(int));
    }
    trip1[0][0] = m1;
    trip1[0][1] = n1;
    trip1[0][2] = nonZero1;
    for (int i = 1; i <= nonZero1; i++) {
        scanf("%d %d %d", &trip1[i][0], &trip1[i][1], &trip1[i][2]);
    }
    printf("\nEnter 2nd triplet: ");
    scanf("%d %d %d", &m2, &n2, &nonZero2);
    if (m1 != m2 || n1 != n2) {
        printf("Order does NOT match!");
        exit(0);
    }
    int **trip2 = (int **) malloc((nonZero2 + 1) * sizeof(int *));
    for (int i = 0; i <= nonZero2; i++) {
        trip2[i] = (int *) malloc(3 * sizeof(int));
    }
    trip2[0][0] = m2;
    trip2[0][1] = n2;
    trip2[0][2] = nonZero2;
    for (int i = 1; i <= nonZero2; i++) {
        scanf("%d %d %d", &trip2[i][0], &trip2[i][1], &trip2[i][2]);
    }
    printf("\nDifference: ");
    int **diff = sub(trip1, trip2);
    int nonZeroD = diff[0][2];
    for (int i = 0; i <= nonZeroD; i++) {
        printf("\n%d %d %d", diff[i][0], diff[i][1], diff[0][2]);
    }
    for (int i = 0; i <= nonZero1; i++) {
        free(trip1[i]);
    }
    free(trip1);
    for (int i = 0; i <= nonZero2; i++) {
        free(trip2[i]);
    }
    free(trip2);
    for (int i = 0; i <= nonZeroD; i++) {
        free(diff[i]);
    }
    free(diff);
    return 0;
}