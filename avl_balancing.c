#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node* left;
    struct node* right;
    int height;
};

// Function to create a new node with the given key
struct node* createNode(int key)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Function to get the height of a node
int getHeight(struct node* n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

// Function to calculate the balance factor of a node
int getBalanceFactor(struct node* n)
{
    if (n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

// Function to update the height of a node
void updateHeight(struct node* n)
{
    int leftHeight = getHeight(n->left);
    int rightHeight = getHeight(n->right);
    n->height = (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// Function to perform a right rotation
struct node* rightRotate(struct node* y)
 {
    struct node* x = y->left;
    struct node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Function to perform a left rotation
struct node* leftRotate(struct node* x)
{
    struct node* y = x->right;
    struct node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Function to insert a key into the AVL tree
struct node* insert(struct node* root, int key)
{
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key || key== root->key)
        root->right = insert(root->right, key);
    else
        return root; // Duplicate keys are not allowed in AVL trees

    updateHeight(root);

    int balanceFactor = getBalanceFactor(root);

    // Left Left Case
    if (balanceFactor > 1 && key < root->left->key)
        return rightRotate(root);

    // Right Right Case
    if (balanceFactor < -1 && key > root->right->key)
        return leftRotate(root);

    // Left Right Case
    if (balanceFactor > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balanceFactor < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to perform preorder traversal of the AVL tree
void preorder(struct node* root)
{
    if (root == NULL)
        return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

// Function to find the node with the minimum key value in a tree
struct node* minValueNode(struct node* node)
{
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a key from the AVL tree
struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL || root->right == NULL)
        {
            struct node* temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            } else
            {
                *root = *temp;
            }
            free(temp);
        }
        else
        {
            struct node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    updateHeight(root);

    int balanceFactor = getBalanceFactor(root);

    // Left Left Case
    if (balanceFactor > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balanceFactor > 1 && getBalanceFactor(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balanceFactor < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balanceFactor < -1 && getBalanceFactor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main()
{
    struct node* root = NULL;
    int choice, key;

    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display (Preorder Traversal)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
         {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Key %d inserted successfully.\n", key);
                printf("\n");
                break;
            case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);

                printf("Key %d deleted successfully.\n", key);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal:\n");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
