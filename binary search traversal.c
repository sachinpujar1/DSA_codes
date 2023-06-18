#include<stdio.h>
#include<stdlib.h>
#include <time.h>
struct node {
    int key;
    struct node *left, *right;
};
struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void INORDER(struct node* root,FILE *s)
{
    if (root != NULL) {
        INORDER(root->left,s);
        fprintf(s,"%d ", root->key);
        INORDER(root->right,s);
    }
}
void PREORDER(struct node* root,FILE *q)
{

    if (root != NULL) {
        fprintf(q,"%d ", root->key);
        PREORDER(root->left,q);
        PREORDER(root->right,q);
    }
}

// Function to perform post-order traversal
void POSTORDER(struct node* root,FILE *z)
{

    if (root != NULL) {
        POSTORDER(root->left,z);
        POSTORDER(root->right,z);
        fprintf(z,"%d ", root->key);
    }
}
struct node* insert(struct node* node, int key)
{
    // If the tree is empty, return a new node
    if (node == NULL)
        return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // Return the (unchanged) node pointer
    return node;
}
int main()
{
    clock_t start, end;
    double cpu_time_used;
    struct node* root = NULL;
    int k,j=0;
     FILE *p; int n;
     FILE *s; FILE *q;
     printf("Enter n\n");
     scanf("%d",&n);
     FILE *z;
      p = fopen("numbers.txt","w");

     for(int i=0;i<n;i++)
     {
         k = rand()%100000;
        fprintf(p,"%d\n",k);
     }
     fclose(p);
     p = fopen("INPUTS.txt","r");
     for(int i=0;i<n;i++)
     {
        fscanf(p,"%d\n",&j);
        root=insert(root,j);
     }
     start = clock();
     s = fopen("INORDER1.txt","w");
     INORDER(root,s);
     end = clock();
     cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("time used INORDER: %f seconds\n", cpu_time_used);
    fclose(s);


    //printf("\nPREORDER: ");
    start = clock();
    q = fopen("PREORDER1.txt","w");
    PREORDER(root,q);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("time used PREORDER: %f seconds\n", cpu_time_used);
    //printf("\nPOSTORDER: ");


    start = clock();
    z = fopen("POSTORDER1.txt","w");
    POSTORDER(root,z);
     end = clock();
     cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("time used POSTORDER: %f seconds\n", cpu_time_used);
}
