#include <stdio.h>
#include <stdlib.h>

typedef struct DLLNode {
    int data;
    struct DLLNode *prev;
    struct DLLNode *next;
} DLLNode;

DLLNode *construct(int data) {
    DLLNode *this = (DLLNode *) malloc(sizeof(DLLNode));
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
    return this;
}

DLLNode *append(DLLNode *this, int data) {
    DLLNode *newNode = construct(data);
    if (this == NULL) {
        this = newNode;
        return this;
    }
    DLLNode *ptr = this;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->prev = ptr;
    return this;
}

void traverse(DLLNode *this) {
    DLLNode *ptr = this;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("null\n");
}

void deleteNafterM(DLLNode **this, int m, int n) {
    if (*this == NULL || m < 0 || n < 0) {
        fprintf(stderr, "\nNull pointer!");
        exit(1);
    } else if (n == 0) {
        return;
    }
    DLLNode *ptr1 = *this;
    for(int i = 1; i < m; i++) {
        if(ptr1 == NULL) {
            fprintf(stderr, "\nNull Pointer!");
            exit(1);
        }
        ptr1 = ptr1->next;
    }
    DLLNode *ptr2 = ptr1->next;
    for(int i = 1; i <= n; i++) {
        if(ptr2 == NULL) {
            fprintf(stderr, "\nNull Pointer!");
            exit(1);
        }
        ptr2 = ptr2->next;
    }
    DLLNode *dump = ptr1->next;
    ptr1->next = ptr2;
    ptr2->prev = ptr1;
    for(int i = 1; i < n; i++) {
        DLLNode *temp = dump;
        dump = dump->next;
        free(temp);
    }
}

int main() {
    int len;
    printf("\nEnter list length: ");
    scanf("%d", &len);
    DLLNode *head = NULL;
    int data;
    printf("\nEnter list elements: ");
    for (int i = 0; i < len; i++) {
        scanf("%d", &data);
        head = append(head, data);
    }
    int m, n;
    printf("\nEnter m & n: ");
    scanf("%d %d", &m, &n);
    deleteNafterM(&head, m , n);
    traverse(head);
    return 0;
}