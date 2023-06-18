#include<stdio.h>

int main()
{

    FILE *p;
    p=fopen("random4.txt","w");
    int n;
    int a[10];
    printf("enter the no of elements\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        struct Node* root = NULL;

        a[i]=rand()%100000;

    }
    fprintf(p,"before sort\n");
    for(int i=0;i<n;i++)
    {
        fprintf(p,"%d\n",a[i]);

    }


}

