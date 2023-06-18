#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n,b,i;
    scanf("%d",&n);
    if(n<=0)
    {
        printf("array should be greater than 0.");

    }
    int a[n];

    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);

    }
   for(i=0;i<n;i++)
    {
    printf("%d ",a[i]);

    }
    printf("\n");
    scanf("%d",&b);
    for(i=0;i<n;i++)
    {
        if (a[i]==b)
        {
            printf("Search successfull. %d found in list.",b );
            exit(0) ;
        }
    }
     for(i=0;i<n;i++)

    {
         if(a[i]!=b)
        {
          printf("Search unsuccessfull. %d not found in list.",b );
             break;
        }
    }
      return 0;
    }

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void replace(char str[9999],char op[10],char oz[10]);
int main()
{
    char str[9999];
    char op[10];
    char oz[10] ;
    printf("Enter word to be replaced\n");
    scanf("%s",op);
    printf("enter new word\n");
    scanf("%s",oz);
    FILE *p;
    p = fopen("clg.txt","r");
    fscanf(p," %[^\n]%*c",&str);
    printf("%s",str);
    replace(str,op,oz);
    FILE *s;
    s = fopen("upd.txt","w");
    fprintf(s,"%s",str);
}
void replace(char str[9999],char op[10],char oz[10])
{
 int l1 = strlen(op);
    int l2 = strlen(oz);
    int j=0,f=0,m=0;
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]==op[j])
        {
            f++;
        }
        j++;
        if(f==l1)
        {
            m=j-f;
              for(int y=m;y<l2;y++)
              {
                str[y] = oz[y];
              }
        }
    }
}
