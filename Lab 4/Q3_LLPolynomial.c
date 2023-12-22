// 4.3 Write a program to represent the polynomial equation of single variable using single linked list and
// perform the addition of two polynomial equations.

#include <stdio.h>
#include <stdlib.h>

typedef struct Polynomial {
    int coeff;
    int deg;
    struct Polynomial *next;
} Polynomial;

Polynomial *construct(int coeff, int deg) {
    Polynomial *term = (Polynomial *) malloc(sizeof(Polynomial));
    term->coeff = coeff;
    term->deg = deg;
    term->next = NULL;
    return term;
}

void append(Polynomial **this, int coeff, int deg) {
    Polynomial *term = construct(coeff, deg);
    if (*this == NULL) {
        *this = term;
    } else {
        Polynomial *ptr = *this;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = term;
    }
}

Polynomial *add(Polynomial *polym1, Polynomial *polym2) {
    Polynomial *sum = NULL;
    while (polym1 != NULL && polym2 != NULL) {
        if (polym1->deg > polym2->deg) {
            append(&sum, polym1->coeff, polym1->deg);
            polym1 = polym1->next;
        } else if (polym1->deg < polym2->deg) {
            append(&sum, polym2->coeff, polym2->deg);
            polym2 = polym2->next;
        } else {
            append(&sum, polym1->coeff + polym2->coeff, polym1->deg);
            polym1 = polym1->next;
            polym2 = polym2->next;
        }
    }
    while (polym1 != NULL) {
        append(&sum, polym1->coeff, polym1->deg);
        polym1 = polym1->next;
    }
    while (polym2 != NULL) {
        append(&sum, polym2->coeff, polym2->deg);
        polym2 = polym2->next;
    }
    return sum;
}

void display(Polynomial *polym) {
    if (polym == NULL) {
        printf("\n0");
        return;
    }
    while (polym != NULL) {
        if (polym->next != NULL) {
            printf("%dx^%d + ", polym->coeff, polym->deg);
        } else {
            printf("%dx^%d", polym->coeff, polym->deg);
        }
        polym = polym->next;
    }
    printf("\n");
}

int main() {
    Polynomial *polym1 = NULL, *polym2 = NULL;
    int coeff, ord1, ord2;
    printf("Enter order of 1st polynomial: ");
    scanf("%d", &ord1);
    printf("Enter coefficients of 1st polynomial: ");
    for (int i = ord1; i >= 0; i--) {
        scanf("%d", &coeff);
        if (coeff != 0) {
            append(&polym1, coeff, i);
        }
    }
    printf("Enter order of 2nd polynomial: ");
    scanf("%d", &ord2);
    printf("Enter coefficients of 2nd polynomial: ");
    for (int i = ord2; i >= 0; i--) {
        scanf("%d", &coeff);
        if (coeff != 0) {
            append(&polym2, coeff, i);
        }
    }
    Polynomial *sum = add(polym1, polym2);
    printf("Sum: ");
    display(sum);
    return 0;
}
