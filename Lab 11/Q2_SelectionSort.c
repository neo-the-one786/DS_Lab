// 11.2 Write a program to sort array of elements in ascending and descending order by selection sort using
// function.

#include <stdio.h>
#include <stdlib.h>

void sSort(int arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        int min = arr[i], minIdx = -1;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < min) {
                min = arr[j];
                minIdx = j;
            }
        }
        if (arr[minIdx] < arr[i]) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
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
    sSort(arr, len);
    display(arr, len);
    return 0;
}