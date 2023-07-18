#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void printTree(struct Node* root, int space) {
    if (root == NULL) {
        return;
    }

    space += 10;

    printTree(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(i == space - 1 ? "|-" : "  ");
    }
    printf("%d\n", root->data);

    printTree(root->left, space);
}

struct Node* findMinValueNode(struct Node* node) {
    struct Node* current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMinValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, i, data, deleteData;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Randomly generated values: ");
    for (i = 1; i < n; i++) {
        data = rand() % 100;
        printf("%d ", data);
        root = insert(root, data);
    }

    printf("\n\nBinary Search Tree Structure (before deletion):\n");
    printTree(root, 0);

    printf("\nEnter the node to delete: ");
    scanf("%d", &deleteData);

    printf("\nBinary Search Tree before deletion: ");
    inorderTraversal(root);

    root = deleteNode(root, deleteData);

    printf("\nBinary Search Tree after deletion: ");
    inorderTraversal(root);

    printf("\n\nBinary Search Tree Structure (after deletion):\n");
    printTree(root, 0);

    return 0;
}
