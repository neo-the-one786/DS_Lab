// 1.4 Write a menu driven program to create a structure to represent complex number and perform the
// following operation using function :
// 1. addition of two complex number (call by value)
// 2. multiplication of two complex number (call by address)

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int re;
    int im;
} ComplexNumber;

ComplexNumber add(ComplexNumber cmplxNum1, ComplexNumber cmplxNum2) {
    ComplexNumber cmplxSum;
    cmplxSum.im = cmplxNum1.im + cmplxNum2.im;
    cmplxSum.re = cmplxNum1.re + cmplxNum2.re;
    while (cmplxSum.im > 9) {
        cmplxSum.re++;
        cmplxSum.im /= 10;
    }
    return cmplxSum;
}

ComplexNumber multiply(ComplexNumber cmplxNum1, ComplexNumber cmplxNum2) {
    ComplexNumber cmplxProd;
    cmplxProd.re = cmplxNum1.re * cmplxNum2.re - cmplxNum1.im * cmplxNum2.im;
    cmplxProd.im = cmplxNum1.re * cmplxNum2.im + cmplxNum1.im * cmplxNum2.re;
    return cmplxProd;
}

int main() {
    ComplexNumber cmplxNum1, cmplxNum2;
    printf("\nEnter first complex number: ");
    scanf("%d %d", &cmplxNum1.re, &cmplxNum1.im);
    printf("Enter second complex number: ");
    scanf("%d %d", &cmplxNum2.re, &cmplxNum2.im);
    short opt;
    do {
        printf("Menu:\nEnter 1 for addition\nEnter 2 for multiplication\nEnter 3 for exit");
        printf("\nEnter your choice: ");
        scanf("%hi", &opt);
        switch (opt) {
            case 1: {
                ComplexNumber cmplxSum = add(cmplxNum1, cmplxNum2);
                printf("Sum: %d + %di\n", cmplxSum.re, cmplxSum.im);
                break;
            }
            case 2: {
                ComplexNumber cmplxProd = multiply(cmplxNum1, cmplxNum2);
                printf("Product: %d + %di\n", cmplxProd.re, cmplxProd.im);
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid Input\n");
                break;
            }
        }
    } while (opt != 3);
    return 0;
}
