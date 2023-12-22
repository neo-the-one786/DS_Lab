// 11.1 Write a program to sort array of elements in ascending and descending order by insertion sort using
// function.

#include <stdio.h>
#include <stdlib.h>

void iSort(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

void display(int arr[], int len) {
    printf("\n{");
    for (int i = 0; i < len; i++) {
        if (i < len - 1) {
            printf("%d, ", arr[i]);
        } else {
            printf("%d", arr[i]);
        }
    }
    printf("}\n");
}

int main() {
    int len;
    printf("\nEnter array length: ");
    scanf("%d", &len);
    printf("Enter array elements: ");;
    int *arr = (int *) calloc(len, sizeof(int));
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    iSort(arr, len);
    display(arr, len);
    return 0;
}