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

void displayPathsHelper(Node *root, int path[], int pathLen) {
    if (root == NULL) {
        return;
    }

    path[pathLen] = root->data;
    pathLen++;

    if (root->left == NULL && root->right == NULL) {
        printf("Path: ");
        for (int i = 0; i < pathLen; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
    } else {
        displayPathsHelper(root->left, path, pathLen);
        displayPathsHelper(root->right, path, pathLen);
    }
}

void displayPaths(Node *root) {
    if (root == NULL) {
        return;
    }

    int path[100]; // Assuming the maximum path length is 100
    displayPathsHelper(root, path, 0);
}

// Other functions like constructNode, traversal functions, etc., if needed

int main() {
    Node *root = constructNode(40), *leftChild = constructNode(20), *rightChild = constructNode(
            50), *leftGrandChild = constructNode(10), *rightGrandChild = constructNode(30);
    root->left = leftChild;
    root->right = rightChild;
    leftChild->left = leftGrandChild;
    leftChild->right = rightGrandChild;

    printf("Paths from root to leaf nodes:\n");
    displayPaths(root);

    return 0;
}
