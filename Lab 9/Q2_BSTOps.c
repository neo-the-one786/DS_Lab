// 9.2 In addition to the 9.1, perform the following menu driven operations on BST.
// i. insert an element to the BST
// ii. display the largest element
// iii. display the smallest element
// iv. height of a node
// v. count number of leaf nodes

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

Node *insertRecur(Node *root, int data) {
    if (root == NULL) {
        return constructNode(data);
    }
    if (data < root->data) {
        root->left = insertRecur(root->left, data);
    } else if (data > root->data) {
        root->right = insertRecur(root->right, data);
    }
    return root;
}

Node *maxRecur(Node *root) {
    if (root == NULL || root->right == NULL) {
        return root;
    }
    return maxRecur(root->right);
}

Node *minRecur(Node *root) {
    if (root == NULL || root->left == NULL) {
        return root;
    }
    return minRecur(root->left);
}

int heightRecur(Node *root) {
    if (root == NULL) {
        return 0;
    }
    return (int) fmax(heightRecur(root->left), heightRecur(root->right)) + 1;
}

void inOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void insertIter(Node **root, int data) {
    Node *newNode = constructNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }
    Node *ptr = *root, *parent = ptr;
    while (ptr != NULL) {
        parent = ptr;
        if (data < ptr->data) {
            ptr = ptr->left;
        } else if (data > ptr->data) {
            ptr = ptr->right;
        } else {
            return;
        }
    }
    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

int maxIter(Node *root) {
    Node *ptr = root;
    while (ptr->right != NULL) {
        ptr = ptr->right;
    }
    return ptr->data;
}

int minIter(Node *root) {
    Node *ptr = root;
    while (ptr->left != NULL) {
        ptr = ptr->left;
    }
    return ptr->data;
}

int main() {
    Node *root = NULL;
    int opt, data;
    do {
        printf("\nEnter 1 for insertion\nEnter 2 for largest\nEnter 3 for smallest\nEnter 4 for height\nEnter 5 for traversal\nEnter 6 to exit");
        printf("\nEnter your choice: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1: {
                printf("\nEnter data to insert: ");
                scanf("%d", &data);
//                root = insertRecur(root, data);
                insertIter(&root, data);
                break;
            }
            case 2: {
                printf("\nMax: %d", maxRecur(root)->data);
                printf("\nMax: %d", maxIter(root));
                break;
            }
            case 3: {
                printf("\nMin: %d", minRecur(root)->data);
                printf("\nMax: %d", minIter(root));
                break;
            }
            case 4: {
                printf("\nHeight: %d", heightRecur(root));
                break;
            }
            case 5: {
                inOrder(root);
                break;
            }
            case 6: {
                exit(0);
            }
            default: {
                fprintf(stderr, "Invalid Input!");
            }
        }
    } while (opt != 6);
    return 0;
}