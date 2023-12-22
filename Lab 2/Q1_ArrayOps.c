// 2.1 WAP to create a 1-D array of n elements and perform the following menu based operations using
// function.
// a. insert a given element at specific position.
// b. delete an element from a specific position of the array.
// c. linear search to search an element
// d. traversal of the array

#include <stdio.h>
#include <stdlib.h>

void insert(int elem, int pos, int arr[], int len) {
    if (pos < 0) {
        printf("Array Index Out of Bounds");
    }
    for (int i = len; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = elem;
}

void delete(int pos, int arr[], int len) {
    if (len <= 0) {
        printf("Empty Array");
    }
    if (pos < 0) {
        printf("Array Index Out of Bounds");
    }
    for (int i = pos; i < len; i++) {
        arr[i] = arr[i + 1];
    }
}

int indexOf(int elem, int arr[], int len) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == elem) {
            return i;
        }
    }
    return -1;
}

void traverse(int arr[], int len) {
    int *ptr = arr;
    while (ptr != &arr[len]) {
        printf("\n%d", *ptr);
        ptr++;
    }
}

int main() {
    int len, elem, pos;
    printf("\nEnter array length: ");
    scanf("%d", &len);
    int *arr = (int *) calloc(len, sizeof(int));
    printf("\nEnter array elements: ");
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    int opt;
    do {
        printf("\nMenu:\nEnter 1 for insertion\nEnter 2 for deletion\nEnter 3 for search\nEnter 4 for traversal\nEnter 5 for exit");
        printf("\nEnter your option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1: {
                printf("\nEnter element: ");
                scanf("%d", &elem);
                printf("\nEnter position: ");
                scanf("%d", &pos);
                insert(elem, pos, arr, len);
                for (int i = 0; i <= len; i++) {
                    printf("\n%d", arr[i]);
                }
                break;
            }
            case 2: {
                printf("\nEnter position: ");
                scanf("%d", &pos);
                delete(pos, arr, len);
                for (int i = 0; i < len - 1; i++) {
                    printf("\n%d", arr[i]);
                }
                break;
            }
            case 3: {
                printf("\nEnter element: ");
                scanf("%d", &elem);
                printf("\n%d index: %d", elem, indexOf(elem, arr, len));
                break;
            }
            case 4: {
                traverse(arr, len);
                break;
            }
            case 5 : {
                free(arr);
                exit(0);
            }
            default: {
                printf("\nInvalid input");
            }
        }
    } while (opt != 5);
    return 0;
}