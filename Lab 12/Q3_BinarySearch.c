// 12.3 Write a program to search a given element within array using binary search.

#include <stdio.h>
#include <stdlib.h>

int bSearchIter(int arr[], int len, int key) {
    int left = 0, right = len - 1, mid = (left + right) / 2;
    while (left <= right) {
        if (key == arr[mid]) {
            return mid;
        } else if (key < arr[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
        mid = (left + right) / 2;
    }
    return -1;
}

int bSearchRecur(int arr[], int left, int right, int key) {
    if (left > right) {
        return -1;
    }
    int mid = (left + right) / 2;
    if (key == arr[mid]) {
        return mid;
    } else if (key < arr[mid]) {
        return bSearchRecur(arr, left, mid - 1, key);
    } else {
        return bSearchRecur(arr, mid + 1, right, key);
    }
}

int main() {
    int len, key;
    printf("\nEnter array length: ");
    scanf("%d", &len);
    printf("Enter array elements: ");;
    int *arr = (int *) calloc(len, sizeof(int));
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nEnter element: ");
    scanf("%d", &key);
    if (bSearchIter(arr, len, key) != -1) {
        printf("\n%d found at index: %d", key, bSearchIter(arr, len, key));
    } else {
        printf("\n%d NOT found!", key);
    }
    if (bSearchRecur(arr, 0, len - 1, key) != -1) {
        printf("\n%d found at index: %d", key, bSearchRecur(arr, 0, len - 1, key));
    } else {
        printf("\n%d NOT found!", key);
    }
    return 0;
}