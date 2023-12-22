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

void deleteLeafNodes(Node *root) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        free(root);
        root = NULL;
        return;
    }
    if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
        free(root->left);
        root->left = NULL;
    }
    if (root->right != NULL && root->right->left == NULL && root->right->right == NULL) {
        free(root->right);
        root->right = NULL;
    }
    deleteLeafNodes(root->left);
    deleteLeafNodes(root->right);
}

void preOrderRecur(Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrderRecur(root->left);
    preOrderRecur(root->right);
}

int main() {
    Node *root = constructNode(40), *leftChild = constructNode(20), *rightChild = constructNode(
            50), *leftGrandChild = constructNode(10), *rightGrandChild = constructNode(30);
    root->left = leftChild;
    root->right = rightChild;
    leftChild->left = leftGrandChild;
    leftChild->right = rightGrandChild;
    printf("Binary Tree before deleting leaf nodes (Preorder traversal):\n");
    preOrderRecur(root);
    printf("\n\n");
    deleteLeafNodes(root);
    printf("Binary Tree after deleting leaf nodes (Preorder traversal):\n");
    preOrderRecur(root);
    printf("\n");
    return 0;
}