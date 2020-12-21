#include<stdio.h>
#define maxsize 5
int queue[maxsize],front=-1,rear=-1;
void enqueue();
void dequeue();
void search();
void display();
void main()
{
	int c;
	printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.SEARCH\n5.EXIT\n");
	do
		{
			printf("\nEnter your choice : ");
			scanf("%d",&c);
			switch(c)
				{
					case 1: 
					enqueue();
					break;
					case 2:
					dequeue();
					break;
					case 3:
					display();
					break;
					case 4:
					search();
					break;
					case 5:
					break;
					default:
					printf("Invalid option");
				}
		}while(c!=5);
}

void enqueue()
{
	int item;
	if(front==(rear+1)%maxsize)
		{
			printf("\nCircular Queue is full");
		}
	else
		{
			printf("Enter the element to be inserted : ");
			scanf("%d",&item);
			if(front==-1 && rear==-1)
				{
					front=rear=0;
					queue[rear]=item;
				}
			else
			rear=(rear+1)%maxsize;
			queue[rear]=item;
		}
}

void dequeue()
{
	if(front==-1 && rear==-1)
		{
			printf("\nCircular Queue is empty");
		}
	else
		{
			printf("The element deleted is : %d",queue[front]);
			if (front==rear)
				{
					front=rear=-1;
				}
			else
			//printf("The element deleted is : %d",queue[front]);
			front=(front+1)%maxsize;
		}
}

void search()
{
	int it,i=front,flag=1;
	if(front==-1 && rear==-1)
		{
			printf("\nCircular Queue is empty");
		}
	else
		{	
			printf("\nEnter the element to be searched : ");
			scanf("%d",&it);
			while(i!=rear)
				{
				if(it==queue[i])flag=0;
				i=(i+1)%maxsize;
				}
				if(queue[i]==it)flag=0;
				if(flag==0)
					{printf("Element %d is present..",it);}	
				else
					{printf("\n Element %d not present..",it);}				
		}
}

void display()
{
	int i=front;
	if(front==-1 && rear==-1)
		{
			printf("\nCircular Queue is empty");
		}
	else
		{
			printf("\nElements of circular queue is : ");
			while(i!=rear)
				{
					printf("\t%d",queue[i]);
					i=(i+1)%maxsize;
				}
			printf("\t%d",queue[rear]);
		}
}