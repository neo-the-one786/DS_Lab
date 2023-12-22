// 5.1 Write a program to create a double linked list and perform the following menu based operations on it:
// i. insert an element at specific position
// ii. delete an element from specific position
// iii. Traverse the list

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node *construct(int data) {
    Node *this = (Node *) malloc(sizeof(Node));
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
    return this;
}

void insertAt(Node **this, int data, int pos) {
    Node *newNode = construct(data);
    if (pos < 1) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    if (pos == 1) {
        newNode->next = *this;
        if (*this != NULL) {
            (*this)->prev = newNode;
        }
        *this = newNode;
        return;
    }

    Node *ptr = *this;
    int c = 1;
    while (ptr != NULL && c < pos - 1) {
        ptr = ptr->next;
        c++;
    }

    if (ptr == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = ptr->next;
    newNode->prev = ptr;
    if (ptr->next != NULL) {
        ptr->next->prev = newNode;
    }
    ptr->next = newNode;
}

void deleteAt(Node **this, int pos) {
    if (*this == NULL || pos < 0) {
        fprintf(stderr, "\nNull Pointer!");
        return;
    }
    Node *ptr = *this;
    if (pos == 0) {
        *this = (*this)->next;
        if (*this != NULL) {
            (*this)->prev = NULL;
        }
        free(ptr);
        return;
    }
    int c = 1;
    while (ptr != NULL) {
        if (c == pos - 1) {
            Node *temp = ptr->next;
            if (ptr->next != NULL) {
                ptr->next = ptr->next->next;
            }
            if (ptr->next != NULL) {
                ptr->next->prev = ptr;
            }
            free(temp);
            return;
        }
        ptr = ptr->next;
        c++;
    }
    fprintf(stderr, "\nIndex Out Bounds!");
}

void traverse(Node *this) {
    printf("The list is: ");
    while (this != NULL) {
        printf("%d", this->data);
        if (this->next != NULL) {
            printf(" <-> ");
        }
        this = this->next;
    }
    printf("null\n");
}

int main() {
    int size, elem, pos;
    printf("\nEnter number of nodes: ");
    scanf("%d", &size);
    printf("\nEnter list elements: ");
    Node *head;
    for (int i = 0; i < size; i++) {
        scanf("%d", &elem);
        if (i == 0) {
            head = construct(elem);
        } else {
            insertAt(&head, elem, i);
        }
    }
    short opt;
    do {
        printf("\nMENU:\nEnter 1 for insertion at position\nEnter 2 for deletion at position\nEnter 3 for traversal\nEnter 4 for exit");
        printf("Enter your choice: ");
        scanf("%hd", &opt);
        switch (opt) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &elem);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAt(&head, elem, pos);
                printf("Node inserted\n");
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAt(&head, pos);
                printf("Node deleted\n");
                break;
            case 3:
                traverse(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid input!\n");
        }
    } while (opt != 4);
    return 0;
}
