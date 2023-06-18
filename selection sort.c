#include<stdio.h>
main()
{
int temp=0;
int a[10];
int n;
printf("enter n\n");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
    scanf("%d",&a[i]);
}
for(int i=0;i<n-1;i++)
{
int min=i;
for(int j=i+1;j<n;j++)
{
if(a[j]<a[min])
{
temp=a[min];
a[min]=a[j];
a[j]=temp;
}
if(min!=i)
{
min=j;
}
}
}
for(int i=0;i<n;i++)
{
printf("%d",a[i]);
}
}
