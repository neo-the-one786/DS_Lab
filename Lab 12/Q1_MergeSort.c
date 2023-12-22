// 12.1 Write a program to perform merge sort on array of elements to arrange it in ascending order using
// function.

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high) {
    int *temp = (int *) calloc(high - low + 1, sizeof(int));
    int left = low, right = mid + 1;
    int i = 0;
    while (left <= mid && right <= high) {
        if (arr[left] < arr[right]) {
            temp[i++] = arr[left++];
        } else {
            temp[i++] = arr[right++];
        }
    }
    while (left <= mid) {
        temp[i++] = arr[left++];
    }
    while (right <= high) {
        temp[i++] = arr[right++];
    }
    for (i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mSortHelper(int arr[], int low, int high) {
    if (low == high) {
        return;
    }
    int mid = (low + high) / 2;
    mSortHelper(arr, low, mid);
    mSortHelper(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void mSort(int arr[], int len) {
    mSortHelper(arr, 0, len - 1);
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
    mSort(arr, len);
    display(arr, len);
    return 0;
}