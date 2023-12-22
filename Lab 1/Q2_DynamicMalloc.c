// 1.2 Write a program to create an array of n elements using dynamic memory allocation. Calculate sum of
// all the prime elements of the array using function and de-allocate the memory of the array after its use.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int val) {
    if(val == 1) {
        return false;
    }
    int count = 0;
    for(int i = 2; i <= sqrt(val); i++) {
        if(val % i == 0) {
            count++;
        }
    }
    if(count == 0) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int len;
    printf("\nEnter array length: ");
    scanf ("\n%d", &len);
    int *arr = (int*) malloc(len * sizeof(int));
    printf("\nEnter array elements: ");
    for(int i = 0; i < len; i++) {
        scanf("\n%d", &arr[i]);
    }
    int primeSum = 0;
    for(int i = 0; i < len; i++) {
        if(isPrime(arr[i])) {
            primeSum += arr[i];
        }
    }
    printf("\nPrime Sum: %d", primeSum);
    free(arr);
    return 0;
}