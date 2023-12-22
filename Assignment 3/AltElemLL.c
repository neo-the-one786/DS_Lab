// 3.1 Design algorithm to create a new linked list from a given linked list. The new linked list must contain
// every alternate element of the existing linked list.


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *construct(int data) {
    Node *this = (Node *) malloc(sizeof(Node));
    this->data = data;
    this->next = NULL;
    return this;
}

Node *append(Node *this, int data) {
    Node *newNode = construct(data);
    if (this == NULL) {
        this = newNode;
        return this;
    }
    Node *ptr = this;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    return this;
}

void traverse(Node *this) {
    Node *ptr = this;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("null\n");
}

Node *pickAlt(Node *head1, Node *head2) {
    Node *ptr = head1;
    int c = 0;
    while (ptr != NULL) {
        if (c % 2 == 0) {
            head2 = append(head2, ptr->data);
        }
        ptr = ptr->next;
        c++;
    }
    return head2;
}

int main() {
    int len;
    printf("\nEnter list length: ");
    scanf("%d", &len);
    Node *head1 = NULL;
    int data;
    printf("\nEnter list elements: ");
    for (int i = 0; i < len; i++) {
        scanf("%d", &data);
        head1 = append(head1, data);
    }
    Node *head2 = NULL;
    head2 = pickAlt(head1, head2);
    traverse(head2);
    return 0;
}