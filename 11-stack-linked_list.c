#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
struct node
{
	int data;
	struct node *next;
};
struct node *top,*temp,*newnode;
void main()
{
int c;
printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT");
do
	{
	printf("\nEnter the your choice : ");
	scanf("%d",&c);
	switch(c)
		{
		case 1:
		push();
		break;
		case 2:
		pop();
		break;
		case 3:
		display();
		break;
		case 4:
		break;
		default:printf("\n Please enter a valid choice...");
		}
	}while(c!=4);
}
void push(int x)
{
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\n Enter the element to be inserted : ");
	scanf("%d",&newnode->data);
	newnode->next=top;
	top=newnode;
	printf("\n Element inserted is %d",newnode->data);
}
void pop()
{
	int i;
	temp=top;
	if(temp==NULL)
	{
	printf("\nStack is empty");
	}
	else
	{
	i=top->data;
	top=top->next;
	printf("\n Element deleted is %d",i);
	}
}
void display()
{
	temp=top;
	if(temp==NULL)
	{
	printf("\n Stack is empty");
	}
	else
	{
	printf("\n Elements are : ");
	while(temp->next!=NULL)
		{
		printf("\n%d",temp->data);
		temp=temp->next;
		}
	printf("\n%d",temp->data);
	}
}