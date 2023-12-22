#include <stdio.h>
#include <stdlib.h>

typedef struct SLLNode {
    int data;
    struct SLLNode *next;
} SLLNode;

SLLNode *construct(int data) {
    SLLNode *this = (SLLNode *) malloc(sizeof(SLLNode));
    this->data = data;
    this->next = NULL;
    return this;
}

SLLNode *append(SLLNode *this, int data) {
    SLLNode *newSLLNode = construct(data);
    if (this == NULL) {
        this = newSLLNode;
        return this;
    }
    SLLNode *ptr = this;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newSLLNode;
    return this;
}

void traverse(SLLNode *this) {
    SLLNode *ptr = this;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("null\n");
}

void swapK(SLLNode **this, int k) {
    SLLNode *ptr = *this;
    if (k == 0) {
        SLLNode *kPlus1th = ptr->next;
        SLLNode *kPlus2th = ptr->next->next;
        ptr->next = kPlus2th;
        kPlus1th->next = ptr;
        *this = kPlus1th;
        return;
    }
    int count = 0;
    while (ptr != NULL) {
        if(ptr->next->next == NULL) {
            fprintf(stderr, "\nNull Pointer!");
            exit(1);
        }
        if (count == k - 1) {
            SLLNode *kth = ptr->next;
            SLLNode *kPlus1th = ptr->next->next;
            ptr->next = kPlus1th;
            kth->next = kPlus1th->next;
            kPlus1th->next = kth;
            return;
        }
        ptr = ptr->next;
        count++;
    }
}


int main() {
    int len;
    printf("\nEnter list length: ");
    scanf("%d", &len);
    SLLNode *head = NULL;
    int data;
    printf("\nEnter list elements: ");
    for (int i = 0; i < len; i++) {
        scanf("%d", &data);
        head = append(head, data);
    }
    int k;
    printf("\nEnter kth position: ");
    scanf("%d", &k);
    swapK(&head, k);
    traverse(head);
    return 0;
}