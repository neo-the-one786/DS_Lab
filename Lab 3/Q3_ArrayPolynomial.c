// 3.3 WAP to represent the polynomial of single variable using 1-D array and perform the addition of two
// polynomial equations.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *add(int polym1[], int polym2[], int ord1, int ord2) {
    int *sum = (int *) calloc((int) fmax(ord1, ord2) + 1, sizeof(int));
    int i = 0;
    while (i <= ord1 && i <= ord2) {
        sum[i] = polym1[i] + polym2[i];
        i++;
    }
    while (i <= ord1) {
        sum[i] = polym1[i];
        i++;
    }
    while (i <= ord2) {
        sum[i] = polym2[i];
        i++;
    }
    return sum;
}

int main() {
    int ord1, ord2;
    printf("\nEnter order of 1st polynomial: ");
    scanf("%d", &ord1);
    int *polym1 = (int *) calloc((ord1 + 1), sizeof(int));
    printf("\nEnter 1st polynomial: ");
    for (int i = ord1; i >= 0; i--) {
        scanf("%d", &polym1[i]);
    }
    printf("\nEnter order of 2nd polynomial: ");
    scanf("%d", &ord2);
    int *polym2 = (int *) malloc((ord2 + 1) * sizeof(int));
    printf("\nEnter 2nd polynomial: ");
    for (int i = ord2; i >= 0; i--) {
        scanf("%d", &polym2[i]);
    }
    int *sum = add(polym1, polym2, ord1, ord2);
    printf("\nSum: ");
    for (int i = (int) fmax(ord1, ord2); i >= 0; i--) {
        if (i > 0) {
            printf("%dx^%d + ", sum[i], i);
        } else {
            printf("%d", sum[i]);
        }
    }
    free(polym1);
    free(polym2);
    free(sum);
    return 0;
}