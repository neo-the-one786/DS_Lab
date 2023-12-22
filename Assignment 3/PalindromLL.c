#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isPalindrome(SLLNode *this) {
    if(this == NULL || this->next == NULL) {
        return true;
    }
    SLLNode *slow = this, *fast = this;
    while(fast->next != NULL /*odd ke liye*/ && fast->next->next != NULL /*even ke liye*/) {
        slow = slow->next;
        fast = fast->next->next;
    }
    SLLNode *prevNode = NULL, *currNode = slow, *nextNode = NULL;
    while(currNode != NULL) {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    SLLNode *ptr = this, *rev = prevNode;
    while(ptr != NULL && rev != NULL) {
        if(ptr->data != rev->data) {
            return false;
        }
        ptr = ptr->next;
        rev = rev->next;
    }
    return true;
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
    if(isPalindrome(head)) {
        printf("\nPalindrome");
    } else {
        printf("\nNOT Palindrome");
    }
    return 0;
}