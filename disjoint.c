#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
   struct node *rep;
   struct node *next;
   int data;
}*head[50],*tail[50];
static int countroot=0;
void makeSet(int);
struct node* find(int);
void unionSets(int,int);

int main()
{
printf("\nDISJOINT SET DATA STRUCTURE\n\t");
int ch,x,i,j,y,flag=0;
do
{
	printf("\n1.Make Set");
	printf("\n2.Display Representatives");
	printf("\n3.Union");
	printf("\n4.Find set");
	printf("\n5.Exit");
	printf("\nEnter the choice:");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:	printf("Enter new element:\n");
	scanf("%d",&x);
	for(i=0;i<countroot;i++)
	{
		flag=0;
		if(head[i]->data==x)
		{
		printf("Element already present\n");
		flag=1;
		break;
		}
	}
		if(flag==0)
		makeSet(x);
		break;
        case 2:printf("The representatives are:\n");
        for(i=0;i<countroot;i++)
	printf("%d ",head[i]->data);
	printf("\n");                     
	break;
        case 3:printf("Enter first element:\n");
	scanf("%d",&x);
	printf("Enter second element:\n");
	scanf("%d",&y);
	unionSets(x,y);
        printf("Union Performed\n");
	break;
        case 4:	printf("Enter the element:\n");
	scanf("%d",&x);
	struct node *rep=(struct node *)malloc(sizeof(struct node));
	rep=find(x);
	if(rep==NULL)
	printf("Element not present\n");
	else
	printf("The representative of %d is: %d\n",x,rep->data);
	break;
	case 5:break;
	default:printf("Invalid choice.");
	}
	}while(ch!=5);
    return 0;
}

void makeSet(int x)
{
struct node *new=(struct node *)malloc(sizeof(struct node));
new->rep=new;
new->next=NULL;
new->data=x;
head[countroot]=new;
tail[countroot++]=new;
}

struct node* find(int a)
{
int i;
struct node *temp=(struct node *)malloc(sizeof(struct node));
for(i=0;i<countroot;i++)
{
temp=head[i];
while(temp!=NULL)
{
if(temp->data==a)
return temp->rep;
temp=temp->next;
}
}
return NULL;
}

void unionSets(int a,int b)
{
int i,pos,flag=0,j;
struct node *tail2=(struct node *)malloc(sizeof(struct node));
struct node *rep1=find(a);
struct node *rep2=find(b);
if(rep1==NULL||rep2==NULL)
{
printf("Element not present..\n");
return;
}
if(rep1!=rep2)
{
for(j=0;j<countroot;j++)
{
	if(head[j]==rep2)
	{
	pos=j;
	flag=1;
	countroot-=1;
	tail2=tail[j];
	for(i=pos;i<countroot;i++)
	{
	head[i]=head[i+1];
	tail[i]=tail[i+1];
	}
	}
	if(flag==1)
	break;
}
for(j=0;j<countroot;j++)
{
	if(head[j]==rep1)
	{
	tail[j]->next=rep2;
	tail[j]=tail2;
	break;
	}
}
while(rep2!=NULL)
{
rep2->rep=rep1;
rep2=rep2->next;
}
}
}

