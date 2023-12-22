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

Node *copyBinaryTree(Node *root) {
    if (root == NULL) {
        return NULL;
    }

    Node *copiedTree = constructNode(root->data);
    copiedTree->left = copyBinaryTree(root->left);
    copiedTree->right = copyBinaryTree(root->right);

    return copiedTree;
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
    printf("Original Binary Tree (Preorder traversal):\n");
    preOrderRecur(root);
    printf("\n\n");
    Node *copiedTree = copyBinaryTree(root);
    printf("Copied Binary Tree (Preorder traversal):\n");
    preOrderRecur(copiedTree);
    printf("\n");
    return 0;
}