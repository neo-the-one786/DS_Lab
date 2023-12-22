#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data, height;
    struct Node *left, *right;
} Node;

Node *constructNode(int data) {
    Node *this = (Node *)malloc(sizeof(Node));
    this->data = data;
    this->left = NULL;
    this->right = NULL;
    this->height = 1;
    return this;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(Node *root) {
    if (root == NULL)
        return 0;
    return root->height;
}

int getBalanceFactor(Node *root) {
    if (root == NULL)
        return 0;
    return getHeight(root->left) - getHeight(root->right);
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node *insertNode(Node *root, int data) {
    if (root == NULL)
        return constructNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalanceFactor(root);

    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

bool isAVL(Node *root) {
    if (root == NULL)
        return true;

    int balance = getBalanceFactor(root);

    if (balance < -1 || balance > 1)
        return false;

    return isAVL(root->left) && isAVL(root->right);
}

// Other functions like preOrder, inOrder, postOrder, if needed

int main() {
    Node *root = NULL;
    int data;

    // Insert nodes into the binary tree
    // Example: root = insertNode(root, data);

    // Check if the tree is an AVL tree
    if (isAVL(root)) {
        printf("The binary tree is an AVL tree.\n");
    } else {
        printf("The binary tree is not an AVL tree.\n");
    }

    return 0;
}
