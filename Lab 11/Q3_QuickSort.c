//11.3 Write a program to perform quick sort on array of elements to arrange it in ascending order using
//function.

#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int left = low, right = high;
    while (left < right) {
        while (arr[left] <= pivot && left < high) {
            left++;
        }
        while (arr[right] > pivot && right > low) {
            right--;
        }
        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[right];
    arr[right] = temp;
    return right;
}

void qSortHelper(int arr[], int low, int high) {
    if (low >= high) {
        return;
    }
    int partIdx = partition(arr, low, high);
    qSortHelper(arr, low, partIdx - 1);
    qSortHelper(arr, partIdx + 1, high);
}

void qSort(int arr[], int len) {
    qSortHelper(arr, 0, len - 1);
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
    qSort(arr, len);
    display(arr, len);
    return 0;
}