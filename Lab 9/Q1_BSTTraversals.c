// 9.1 Write a program to create a binary search tree of n data elements using linked list and perform the
// following menu driven operations:
// i. preorder traversal
// ii. postorder traversal
// iii. inorder traversal
// iv. search an element

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *constructNode(int data) {
    Node *this = (Node *) malloc(sizeof(Node));
    this->data = data;
    this->left = NULL;
    this->right = NULL;
    return this;
}

void preOrderRecur(Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrderRecur(root->left);
    preOrderRecur(root->right);
}

void inOrderRecur(Node *root) {
    if (root == NULL) {
        return;
    }
    inOrderRecur(root->left);
    printf("%d ", root->data);
    inOrderRecur(root->right);
}

void postOrderRecur(Node *root) {
    if (root == NULL) {
        return;
    }
    postOrderRecur(root->left);
    postOrderRecur(root->right);
    printf("%d ", root->data);
}

Node *searchRecur(Node *root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->data) {
        return searchRecur(root->left, key);
    } else if (key > root->data) {
        return searchRecur(root->right, key);
    } else {
        return root;
    }
}

typedef struct {
    int top, cpty;
    Node **arr;
} Stack;

Stack *constructStack(int cpty) {
    Stack *this = (Stack *) malloc(sizeof(Stack));
    this->cpty = cpty;
    this->arr = (Node **) malloc(this->cpty * sizeof(Node *));
    this->top = -1;
    return this;
}

bool isEmpty(Stack *this) {
    return this->top == -1;
}

bool isFull(Stack *this) {
    return this->top == this->cpty - 1;
}

void push(Stack *this, Node *newNode) {
    if (isFull(this)) {
        return;
    }
    this->arr[++this->top] = newNode;
}

Node *pop(Stack *this) {
    if (isEmpty(this)) {
        return NULL;
    }
    return this->arr[this->top--];
}

#define MAX_VAL 100

void preOrderIter(Node *root) {
    if (root == NULL) {
        return;
    }
    Node *ptr = root;
    Stack *stack = constructStack(MAX_VAL);
    push(stack, ptr);
    while (!isEmpty(stack)) {
        ptr = pop(stack);
        printf("%d ", ptr->data);
        if (ptr->right != NULL) {
            push(stack, ptr->right);
        }
        if (ptr->left != NULL) {
            push(stack, ptr->left);
        }
    }
}

void inOrderIter(Node *root) {
    if (root == NULL) {
        return;
    }
    Node *ptr = root;
    Stack *stack = constructStack(MAX_VAL);
    push(stack, ptr);
    while (!isEmpty(stack)) {
        if (ptr != NULL) {
            push(stack, ptr);
            ptr = ptr->left;
        } else {
            ptr = pop(stack);
            printf("%d ", ptr->data);
            ptr = ptr->right;
        }
    }
}

void postOrderIter(Node *root) {
    if (root == NULL) {
        return;
    }
    Node *ptr = root;
    Stack *s1 = constructStack(MAX_VAL), *s2 = constructStack(MAX_VAL);
    push(s1, ptr);
    while (!isEmpty(s1)) {
        ptr = pop(s1);
        push(s2, ptr);
        if (ptr->left != NULL) {
            push(s1, ptr->left);
        }
        if (ptr->right != NULL) {
            push(s1, ptr->right);
        }
    }
    while (!isEmpty(s2)) {
        printf("%d ", pop(s2)->data);
    }
}

Node *searchIter(Node *root, int key) {
    if (root == NULL) {
        return root;
    }
    Node *ptr = root;
    while (ptr != NULL) {
        if (key < ptr->data) {
            ptr = ptr->left;
        } else if (key > ptr->data) {
            ptr = ptr->right;
        } else {
            return ptr;
        }
    }
    return ptr;
}

int main() {
    Node *root = constructNode(40);
    root->left = constructNode(20);
    root->right = constructNode(50);
    root->left->left = constructNode(10);
    root->left->right = constructNode(30);
    int opt;
    do {
        printf("\nEnter 1 for preorder\nEnter 2 for inorder\nEnter 3 for postorder\nEnter 4 for search\nEnter 5 to exit");
        printf("\nEnter your choice: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1: {
                preOrderRecur(root);
                printf("\n");
                preOrderIter(root);
                break;
            }
            case 2: {
                inOrderRecur(root);
                printf("\n");
                inOrderIter(root);
                break;
            }
            case 3: {
                postOrderRecur(root);
                printf("\n");
                postOrderIter(root);
                break;
            }
            case 4: {
                printf("\nEnter data to search: ");
                int key;
                scanf("%d", &key);
                Node *node = searchRecur(root, key);
                if (node) {
                    printf("\n%d found!", node->data);
                } else {
                    printf("\n%d NOT found!", key);
                }
                node = searchIter(root, key);
                if (node) {
                    printf("\n%d found!", node->data);
                } else {
                    printf("\n%d NOT found!", key);
                }
                break;
            }
            case 5: {
                free(root);
                exit(0);
            }
            default: {
                fprintf(stderr, "Invalid Input!");
            }
        }
    } while (opt != 5);
    return 0;
}