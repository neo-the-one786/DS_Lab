// 4.2 In addition to 4.1, perform following operations using function on the single linked list:
// i. search an element in the list
// ii. sort the list in ascending order
// iii. reverse the list

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int numNodes(Node *this) {
    Node *ptr = this;
    int count = 0;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void insertAt(Node **this, int data, int pos) {
    if (pos < 0) {
        fprintf(stderr, "\nNull Pointer");
        exit(1);
    }
    Node *ptr = *this;
    Node *newNode = construct(data);
    if (pos == 0) {
        newNode->next = *this;
        *this = newNode;
    }
    int count = 0;
    while (ptr != NULL) {
        if (count == pos - 1) {
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
        count++;
        ptr = ptr->next;
    }
}

void deleteAt(Node **this, int pos) {
    if (*this == NULL || pos < 0 || pos >= numNodes(*this)) {
        fprintf(stderr, "\nNull Pointer!\n");
        exit(1);
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
            ptr->next = ptr->next->next;
            free(temp);
            return;
        }
        c++;
        ptr = ptr->next;
    }
}

int search(Node *this, int data) {
    Node *ptr = this;
    int c = 0;
    while (ptr != NULL) {
        if (ptr->data == data) {
            return c;
        }
        c++;
        ptr = ptr->next;
    }
    return -1;
}

void sort(Node **this) {
    if (*this == NULL || (*this)->next == NULL) {
        return;
    }
    Node *i = *this, *j = NULL;
    while (i != NULL) {
        bool swap = false;
        j = i->next;
        while (j != NULL) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
                swap = true;
            }
            j = j->next;
        }
        i = i->next;
        if (!swap) {
            break;
        }
    }
}

void reverse(Node **this) {
    Node *prev = NULL, *curr = *this, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *this = prev;
}

int main() {
    int size, elem;
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
    printf("\nMENU:\nEnter 1 for insertion\nEnter 2 for deletion\nEnter 3 to count nodes\nEnter 4 for traversal");
    printf("\nEnter 5 for searching\nEnter 6 for sorting\nEnter 7 for reversal\nEnter 8 for exit");
    do {
        printf("\nEnter your choice: ");
        scanf("%hd", &opt);
        if (opt == 8) {
            printf("\nExiting");
            return 0;
        }
        int pos;
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
                printf("\nTotal number of nodes: %d", numNodes(head));
                break;
            case 4:
                traverse(head);
                break;
            case 5:
                printf("\nEnter element to be searched: ");
                scanf("%d", &elem);
                int idx = search(head, elem);
                if (idx >= 0) {
                    printf("\nElement found at position: %d", idx);
                } else {
                    printf("\nElement NOT found!");
                }
                break;
            case 6:
                sort(&head);
                break;
            case 7:
                reverse(&head);
                break;
            default:
                printf("Invalid input!");
        }
    } while (opt != 8);
    return 0;
}