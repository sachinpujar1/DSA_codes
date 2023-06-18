#include<stdio.h>
#include<string.h>
struct node
{
int a;
struct node *next;
};
struct node *head,*temp,*newnode;
struct node* insert(struct node*);
void display(struct node*);
void sort(struct node*);
void main()
{
int n;
head=NULL;
while(1)
{
printf("1---Insert at the beginning\n");

printf("2---display details");
printf("3---sort the numbets\n");
printf("enter your choice\n");
scanf("%d",&n);

switch(n)
{

case 1:newnode=malloc(sizeof(struct node));
       printf("enter data\n");
       scanf("%d",&newnode->a);
       head=insert(newnode);
       break;


case 2:display(head);
break;

 case 3:sort(head);


       break;
default:printf("invalid choice\n");
}
}
}
struct node* insert(struct node*newnode)
{
if(head==NULL)
{
head=newnode;
head->next=NULL;
return(head);
}
else
{
newnode->next=head;
head=newnode;
return(head);
}

}
void display(struct node*head)
{
if(head==NULL)
{
printf("Linked list is empty\n");
}
else
{
temp=head;
while(temp!=NULL)
{
printf("%d",temp->a);
temp=temp->next;
}
}

}
void sort(struct node*head)
{

}
