// 4.1 Write a program to create a single linked list of n nodes and perform the following menu based
// operations on it using function:
// i. Insert a node at specific position
// ii. Deletion of an element from specific position
// iii. Count nodes
//iv. Traverse the linked list

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

void traverse(Node *this) {
    Node *ptr = this;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("null\n");
}

int numNode(Node *this) {
    Node *ptr = this;
    int c = 0;
    while (ptr != NULL) {
        c++;
        ptr = ptr->next;
    }
    return c;
}

void insertAt(Node **this, int data, int pos) {
    if (pos < 0 || pos >= numNode(*this)) {
        fprintf(stderr, "\nNull Pointer!");
        return;
    }
    Node *ptr = *this;
    Node *newNode = construct(data);
    if (pos == 0) {
        newNode->next = *this;
        *this = newNode;
        return;
    }
    int c = 0;
    while (ptr != NULL) {
        if (c == pos - 1) {
            newNode->next = ptr->next;
            ptr->next = newNode;
            return;
        }
        c++;
        ptr = ptr->next;
    }
    fprintf(stderr, "Index Out Of Bounds!");
}

void deleteAt(Node **this, int pos) {
    if (*this == NULL || pos < 0 || pos >= numNode(*this)) {
        fprintf(stderr, "\nNull Pointer!\n");
        return;
    }
    Node *ptr = *this;
    if (pos == 0) {
        *this = (*this)->next;
        free(ptr);
        return;
    }
    int c = 0;
    while (ptr != NULL) {
        if (c == pos - 1) {
            Node *temp = ptr->next;
            if (ptr->next != NULL) {
                ptr->next = ptr->next->next;
            }
            free(temp);
            return;
        }
        c++;
        ptr = ptr->next;
    }
    fprintf(stderr, "\nIndex Out Of Bounds!");
}

int main() {
    int n;
    printf("\nEnter number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter list elements: ");
    Node *head;
    int elem, pos;
    for (int i = 0; i < n; i++) {
        scanf("%d", &elem);
        if (i == 0) {
            head = construct(elem);
        } else {
            insertAt(&head, elem, i);
        }
    }
    short opt;
    printf("\nMENU:\nEnter 1 for insertion\nEnter 2 for deletion\nEnter 3 for node count\nEnter 4 for traversal\nEnter 5 for exit");
    do {
        printf("\nEnter your choice: ");
        scanf("%hd", &opt);
        switch (opt) {
            case 1:
                printf("\nEnter element: ");
                scanf("%d", &elem);
                printf("\nEnter position: ");
                scanf("%d", &pos);
                insertAt(&head, elem, pos);
                break;
            case 2:
                printf("\nEnter position: ");
                scanf("%d", &pos);
                deleteAt(&head, pos);
                break;
            case 3:
                printf("Total number of nodes: %d", numNode(head));
                break;
            case 4:
                traverse(head);
                break;
            default:
                printf("Indataid input!");
        }
    } while (opt != 5);
    return 0;
}