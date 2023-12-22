#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *banaao(int data) {
    Node *this = (Node *) malloc(sizeof(Node));
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
    return this;
}

void sahiJagahGhusaao(Node **head, int data, int pos) {
    Node *newNode = banaao(data);
    if (*head == NULL) {
        *head = banaao(data);
        return;
    }
    if (pos == 0) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }
    Node *ptr = *head;
    int count = 0;
    while (ptr != NULL) {
        if (count == pos - 1) {
            newNode->prev = ptr;
            newNode->next = ptr->next;
            ptr->next = newNode;
            if (ptr->next != NULL) {
                ptr->next->prev = newNode;
            }
            return;
        }
        ptr = ptr->next;
        count++;
    }
    if (ptr == NULL) {
        printf("\nIndex out of bounds!");
    }
}

void sahiJagahNikaalo(Node **head, int pos) {
    if ((*head == NULL && pos == 0) || pos < 0) {
        printf("\nNull pointer!");
        return;
    }
    Node *ptr = *head;
    int count = 0;
    if (pos == 0) {
        *head = (*head)->next;
        if (head != NULL) {
            (*head)->prev = NULL;
        }
        free(ptr);
        return;
    }
    while (ptr != NULL) {
        if (count == pos - 1) {
            Node *dump = ptr->next;
            if (ptr->next != NULL) {
                ptr->next = ptr->next->next;
            }
            if(ptr->next != NULL) {
                ptr->next->prev = ptr;
            }
            free(dump);
            return;
        }
        ptr = ptr->next;
        count++;
    }
    if (ptr == NULL) {
        printf("\nIndex out of bounds!");
        return;
    }
}

int khojo(Node *head, int data) {
    Node *ptr = head;
    int idx = 0;
    while (ptr != NULL) {
        if (ptr->data == data) {
            return idx;
        }
        ptr = ptr->next;
        idx++;
    }
    return -1;
}

void aageSeDikhaao(Node *head) {
    Node *ptr = head;
    while (ptr != NULL) {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    }
    printf("null\n");
}

void peechheSeDikhaao(Node *head) {
    if (head == NULL) {
        printf("\nnull");
        return;
    }
    peechheSeDikhaao(head->next);
    printf(" <-> %d", head->data);
}

int main() {
    int len;
    printf("\nEnter list length: ");
    scanf("%d", &len);
    printf("\nEnter list elements: ");
    int data;
    Node *head = NULL;
    for (int i = 0; i < len; i++) {
        scanf("%d", &data);
        sahiJagahGhusaao(&head, data, i);
    };
    short opt;
    int pos;
    do {
        printf("\nMenu:\nEnter 1 to insert at position\nEnter 2 to delete at position\nEnter 3 to search\nEnter 4 to traverse from front\nEnter 5 to traverse from behind\nEnter 6 for exit");
        printf("\nEnter choice: ");
        scanf("%hd", &opt);
        switch (opt) {
            case 1: {
                printf("\nEnter data: ");
                scanf("%d", &data);
                printf("\nEnter position: ");
                scanf("%d", &pos);
                sahiJagahGhusaao(&head, data, pos);
                break;
            }
            case 2: {
                printf("\nEnter position: ");
                scanf("%d", &pos);
                sahiJagahNikaalo(&head, pos);
                break;
            }
            case 3: {
                printf("\nEnter value: ");
                scanf("%d", &data);
                int idx = khojo(head, data);
                if (idx != -1) {
                    printf("\n%d found at index: %d", data, idx);
                } else {
                    printf("\nNo such element!");
                }
                break;
            }
            case 4: {
                aageSeDikhaao(head);
                break;
            }
            case 5: {
                peechheSeDikhaao(head);
                break;
            }
            case 6: {
                exit(1);
            }
            default: {
                printf("\nInvalid Input!");
            }
        }
    } while (opt != 6);
    return 0;
}