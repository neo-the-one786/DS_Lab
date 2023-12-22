// 1.1 Write a program to read two numbers and compare the numbers using function call by address.

#include <stdio.h>

void compare(int *addr1, int *addr2) {
    if (*addr1 > *addr2) {
        printf("\n%d is greater than %d", *addr1, *addr2);
    } else if (*addr1 < *addr2) {
        printf("\n%d is lesser than %d", *addr1, *addr2);
    } else {
        printf("\n%d is equal to %d", *addr1, *addr2);
    }
}

int main() {
    int val1, val2;
    printf("\nEnter two numbers: ");
    scanf("\n%d %d", &val1, &val2);
    compare(&val1, &val2);
    return 0;
}