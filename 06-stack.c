#include<stdio.h>

int stack[100],i,n,e,c,con,top;
void push();
void pop();
void display();

void main()
{
top=-1;
printf("\n Enter the stack size : ");
scanf("%d",&n);
printf("\n1.PUSH");
printf("\n2.POP");
printf("\n3.DISPLAY");
printf("\n4.EXIT");
do
{
printf("\nEnter your choice : ");
scanf("%d",&c);
switch(c)
{
case 1:
{
push();
break;
}
case 2:
{
pop();
break;
}
case 3:
{
display();
break;
}
case 4:return;
default:printf("\nYou entered invalid option");
}
}
while(c!=4);
}

void push()
{
if(top==n-1)
{
printf("Stack is full..");
}
else
{
printf("Enter the number to be inserted/pushed : ");
scanf("%d",&e);
top++;
stack[top]=e;
}
}

void pop()
{
if(top==-1)
{printf("Stack is empty..");}
else
{
printf("The element popped is %d",stack[top]);
top--;
}
}

void display()
{

if(top==-1)
{
printf("Stack is empty..");
}
else
{
printf("Elements of stack are : ");
for(i=top;i>=0;i--)
{
printf("\n %d",stack[i]);
}
}
}