#include <stdio.h>
#include <stdlib.h>

typedef struct Polynomial {
    int coeff;
    int exp;
    struct Polynomial *next;
} Polynomial;

Polynomial *construct(int coeff, int exp) {
    Polynomial *term;
    term = (Polynomial *) malloc(sizeof(Polynomial));
    term->coeff = coeff;
    term->exp = exp;
    term->next = NULL;
    return term;
}

Polynomial *append(Polynomial *polym, int coeff, int exp) {
    Polynomial *term = construct(coeff, exp);
    if (polym == NULL) {
        polym = term;
        return polym;
    }
    Polynomial *ptr = polym;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = term;
    return polym;
}

void display(Polynomial *head) {
    Polynomial *temp1 = head;
    printf("\n");
    while (temp1 != NULL) {
        if (temp1->next != NULL) {
            printf("%dx^%d + ", temp1->coeff, temp1->exp);
        } else {
            printf("%dx^%d", temp1->coeff, temp1->exp);
        }
        temp1 = temp1->next;
    }
}

void checkDuplicates(Polynomial *head3) {
    Polynomial *ptr1 = head3, *ptr2 = ptr1->next;
    Polynomial *prev = ptr1;
    while (ptr1->next != NULL) {
        while (ptr2 != NULL) {
            if (ptr1->exp == ptr2->exp) {
                ptr1->coeff = ptr1->coeff + ptr2->coeff;
                Polynomial *temp = ptr2;
                prev->next = ptr2->next;
                ptr2 = ptr2->next;
                free(temp);
            } else {
                prev = ptr2;
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
        prev = ptr1;
        ptr2 = ptr1->next;
    }
}

Polynomial *multiply(Polynomial *head1, Polynomial *head2, Polynomial *head3) {
    Polynomial *ptr1 = head1, *ptr2 = head2;
    for (; ptr1 != NULL; ptr1 = ptr1->next) {
        for (ptr2 = head2; ptr2 != NULL; ptr2 = ptr2->next) {
            head3 = append(head3, ptr1->coeff * ptr2->coeff, ptr1->exp + ptr2->exp);
        }
    }
    checkDuplicates(head3);
    return head3;
}

Polynomial *add(Polynomial *head1, Polynomial *head2, Polynomial *head3) {
    Polynomial *t1 = head1, *t2 = head2;
    while (t1 != NULL && t2 != NULL) {
        if (t1->exp == t2->exp) {
            head3 = append(head3, t1->coeff + t2->coeff, t1->exp);
            t1 = t1->next;
            t2 = t2->next;
        } else if (t1->exp > t2->exp) {
            head3 = append(head3, t1->coeff, t1->exp);
            t1 = t1->next;
        } else {
            head3 = append(head3, t2->coeff, t2->exp);
            t2 = t2->next;
        }
    }
    while (t1 != NULL) {
        head3 = append(head3, t1->coeff, t1->exp);
        t1 = t1->next;
    }
    while (t2 != NULL) {
        head3 = append(head3, t2->coeff, t2->exp);
        t2 = t2->next;
    }
    return head3;
}

Polynomial *sub(Polynomial *head1, Polynomial *head2, Polynomial *head3) {
    Polynomial *t1 = head1, *t2 = head2;
    while (t1 != NULL && t2 != NULL) {
        if (t1->exp == t2->exp) {
            head3 = append(head3, t1->coeff - t2->coeff, t1->exp);
            t1 = t1->next;
            t2 = t2->next;
        } else if (t1->exp > t2->exp) {
            head3 = append(head3, t1->coeff, t1->exp);
            t1 = t1->next;
        } else {
            head3 = append(head3, -t2->coeff, t2->exp);
            t2 = t2->next;
        }
    }
    while (t1 != NULL) {
        head3 = append(head3, t1->coeff, t1->exp);
        t1 = t1->next;
    }
    while (t2 != NULL) {
        head3 = append(head3, -t2->coeff, t2->exp);
        t2 = t2->next;
    }
    return head3;
}

int main() {
    int ord1;
    Polynomial *polym1 = NULL;
    printf("\nEnter the ord of polynomial 1: ");
    scanf("%d", &ord1);
    printf("\nEnter the coefficents: ");
    int coeff;
    for (int i = ord1; i >= 0; i--) {
        scanf("%d", &coeff);
        polym1 = append(polym1, coeff, i);
    }
    int ord2;
    Polynomial *polym2 = NULL;
    printf("\nEnter the ord of polynomial 2: ");
    scanf("%d", &ord2);
    printf("\nEnter the coefficents: ");
    for (int i = ord2; i >= 0; i--) {
        scanf("%d", &coeff);
        polym2 = append(polym2, coeff, i);
    }
    display(polym1);
    display(polym2);
    Polynomial *sum = NULL, *prod = NULL;
    printf("\nSum: ");
    sum = add(polym1, polym2, sum);
    display(sum);
    printf("\nProduct: ");
    prod = multiply(polym1, polym2, prod);
    display(prod);
    return 0;
}