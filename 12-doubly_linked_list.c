#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head,*newnode,*temp,*rear;
int c,i;
void insertbeg();
void insertpos();
void insertend();
void deletebeg();
void deletepos();
void deleteend();
void search();
void display();
void main()
{
	int c;
	printf("\n1.Insert at beginning");
	printf("\n2.Insert at specific position");
	printf("\n3.Insert at end");
	printf("\n4.Delete from beginning");
	printf("\n5.Delete from specific position");
	printf("\n6.Delete from end");
	printf("\n7.Search");
	printf("\n8.Display");
	printf("\n9.Exit");
	do
	{
	printf("\nEnter your choice : ");
	scanf("%d",&c);
	switch(c)
		{
		case 1:insertbeg();break;
		case 2:insertpos();break;
		case 3:insertend();break;
		case 4:deletebeg();break;
		case 5:deletepos();break;
		case 6:deleteend();break;
		case 7:search();break;
		case 8:display();break;
		case 9:break;
		default:printf("\n Please enter a valid option..");
		}
	}while(c!=9);

}



void insertbeg()
{
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter a number : ");
	scanf("%d",&newnode->data);
	if(head==NULL)
	{
		newnode->next=NULL;
		newnode->prev=NULL;
		head=rear=newnode;
		c++;
	}
	else
	{
		temp=head;
		head=newnode;
		newnode->next=temp;
		temp->prev=head;
		newnode->prev=NULL;
		c++;
	}
}




void insertpos()
{
	temp=head;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter a number : ");
	scanf("%d",&newnode->data);
	if(head==NULL)
	{
		newnode->next=NULL;
		newnode->prev=NULL;
		head=rear=newnode;
		c++;
	}
	else
	{
		int p;
		printf("\n Enter the position: ");
		scanf("%d",&p);
		if(p>c+1 || p<1)
		{
			printf("\nEnter a position: ");
		}
		for(i=1;i<p-1;i++)
		{
			temp=temp->next;
		}
		if(p==1)
		{
			newnode->next=head;
			head->prev=newnode;
			newnode->prev=NULL;
			head=newnode;
		}
		else
		{
			newnode->next=temp->next;
			temp->next=newnode;
			newnode->prev=temp;
			if((newnode->next)!=NULL)
				(newnode->next)->prev=newnode;
			else
				rear=newnode;
		}
			c++;
		
	}
}




void insertend()
{
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter a number : ");
	scanf("%d",&newnode->data);
	if(head==NULL)
	{
		newnode->next=NULL;
		newnode->prev=NULL;
		head=rear=newnode;
		c++;
	}
	else
	{
		temp=rear;
		temp->next=newnode;
		newnode->next=NULL;
		newnode->prev=temp;
		rear=newnode;
		c++;
	}
}




void deletebeg()
{
	int element;
	if(head==NULL)
	{
		printf("\nEmpty list");
	}
	else if(head->next==NULL)
	{
		element=head->data;
		head=rear=NULL;
		printf("\nDeleted element is %d",element);
		c--;
	}
	else
	{
		temp=head;
		element=head->data;
		head=temp->next;
		head->prev=NULL;
		printf("\nDeleted element is %d",element);
		c--;
	}
}

void deletepos()
{
	int p,element;
	if(head==NULL)
	{
		printf("\nEmpty list");
	}
	else 
	{
		if(c==1)
		{
		element=head->data;
		head=rear=NULL;
		}
		else
		{
		printf("\nEnter the position : ");
		scanf("%d",&p);
		temp=head;
		if(p>c || p<1)
		{
			printf("\nEnter a position: ");
		}
		for(i=1;i<p;i++)
		{
			temp=temp->next;
		}
		if(p==1)
		{
			element=head->data;
			head=head->next;
			head->prev=NULL;
		}
		else
		{
			element=temp->data;
			(temp->prev)->next=temp->next;
			if(temp->next!=NULL)
				(temp->next)->prev=temp->prev;
			else
				rear=temp->prev;
		}
		}
	printf("\nDeleted element is %d",element);
	c--;
	}
}



void deleteend()
{
	int element;
	if(head==NULL)
	{
		printf("\nEmpty list");
	}
	else if(head->next==NULL)
		{
		element=head->data;
		head=rear=NULL;
		printf("\nDeleted element is %d",element);
		c--;
		}
		else
		{
		temp=rear;
		element=temp->data;
		rear=temp->prev;
		rear->next=NULL;
		printf("\nDeleted element is %d",element);
		c--;
		}
}


void search()
{
	int e,e1;
	if(head==NULL)
	{
		printf("\nEmpty list");
	}
	else
	{
		printf("\nEnter the element to be searched : ");
		scanf("%d",&e);
		temp=head;
		e1=0;
		while(temp!=rear)
		{
		if(temp->data==e)
		e1++;
		temp=temp->next;
		}
		if(e1>0)
		{
		printf("\n %d present and occures %d times",e,e1);
		}
		else
		{
		printf("\n %d not present",e);
		}
	}
}




void display()
{
	if(head==NULL)
	{
	printf("\nEmpty list");
	}
	else
	{
		printf("\nElements are : ");
		temp=head;
		while(temp!=rear)
		{
		printf("\t%d",temp->data);
		temp=temp->next;
		}
		printf("\t%d",temp->data);
	}
}