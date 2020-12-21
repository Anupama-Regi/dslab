#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
# define MAX 5
int queue[MAX],i,c,front,rear;
void insert();
void delete();
void display();
void main()
{
front=-1;
rear=-1;
printf("\n1.Insert");
printf("\n2.Delete");
printf("\n3.Display");
printf("\n4.Quit");
do
{
printf("\nEnter your choice : ");
scanf("%d",&c);
switch(c)
{
case 1:
{
insert();
break;
}
case 2:
{
delete();
break;
}
case 3:
{
display();
break;
}
case 4:
return;
default:
printf("\nYou enter a invalid option..");
}
}
while(c!=4);
getch();
}


void insert()
{
int item;
if(rear==MAX-1)
{
printf("\n Queue is full..");
}
else
{
printf("\n Enter the element to be inserted : ");
scanf("%d",&item);
rear++;
queue[rear]=item;
if(front==-1)
{
front=0;
rear=0;
}
}
}

void delete()
{
if(rear==-1)
{
printf("\n Queue is empty");
}
else
{
printf("\n The deleted element is %d",queue[front]);
if(front==rear)
{
front=-1;
rear=-1;
}
front++;
}
}

void display()
{
if(rear==-1)
{
printf("\nQueue is empty");
}
else
{
printf("\n Elements are : ");
for(i=front;i<=rear;i++)
{
printf("\t%d",queue[i]);
}
}
}