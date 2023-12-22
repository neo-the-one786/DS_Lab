// 9.3 In addition to 9.2, perform deletion of an element in the BST using function.

#include <stdio.h>
#include <stdlib.h>

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

Node *deleteRecur(Node *root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteRecur(root->left, data);
        return root;
    } else if (data > root->data) {
        root->right = deleteRecur(root->right, data);
        return root;
    }
    if (root->left == NULL) {
        Node *temp = root->right;
        free(root);
        return temp;
    } else if (root->right == NULL) {
        Node *temp = root->left;
        free(root);
        return temp;
    } else {
        Node *parent = root, *ptr = root->right;
        while (ptr->left != NULL) {
            parent = ptr;
            ptr = ptr->left;
        }
        if (parent != NULL) {
            parent->left = ptr->right;
        } else {
            parent->right = ptr->right;
        }
        root->data = ptr->data;
        free(ptr);
        return root;
    }
}

void inOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int main() {
    Node *root = constructNode(40);
    root->left = constructNode(20);
    root->right = constructNode(50);
    root->left->left = constructNode(10);
    root->left->right = constructNode(30);
    int opt, data;
    do {
        printf("\nEnter 1 for deletion\nEnter 2 for traversal\nEnter 3 to exit");
        printf("\nEnter your choice: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1: {
                printf("\nEnter data to delete: ");
                scanf("%d", &data);
                deleteRecur(root, data);
                printf("\n%d deleted", data);
                break;
            }
            case 2: {
                inOrder(root);
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                fprintf(stderr, "Invalid Input!");
            }
        }
    } while (opt != 6);
    return 0;
}