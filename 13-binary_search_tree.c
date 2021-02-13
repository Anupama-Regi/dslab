#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *leftchild;
struct node *rightchild;
};
typedef struct node st;
st* insert(st*,int);
st* delete(st*,int);
st* delete_successor(st*);
void search(st*,int);
void inOrder(st*);
void preOrder(st*);
void postOrder(st*);
int main()
{
	int c,i,d,s;
	st* root,*sn;
	root=NULL;
	printf("\n1.Insertion");
	printf("\n2.Deletion");
	printf("\n3.Search");
	printf("\n4.IN Order Traversal");
	printf("\n5.PRE Order Traversal");
	printf("\n6.POST Order Traversal");
	printf("\n7.Exit");
	do
	{
	printf("\n\nEnter your choice : ");
	scanf("%d",&c);
	switch(c)
		{
		case 1: 
			printf("\nEnter data to be inserted : ");
			scanf("%d",&i);
			root=insert(root,i);
			printf("\n%d inserted...Root is %d",i,root->data);
			break;
		case 2: 
			if(root==NULL)
			{
			printf("Tree is empty...");
			break;
			}
			printf("\nEnter data to be deleted : ");
			scanf("%d",&d);
			root=delete(root,d);
			break;
		case 3: 
			if(root==NULL)
			{
			printf("Tree is empty...");
			break;
			}
			printf("\nEnter the data to be searched : ");
			scanf("%d",&s);
			search(root,s);
			break;
		case 4: 
			if(root==NULL)
			{
			printf("\n Tree is empty...");
			break;
			}
			inOrder(root);
			break;
		case 5: 
			if(root==NULL)
			{
			printf("\n Tree is empty...");
			break;
			}
			preOrder(root);
			break;
		case 6: 
			if(root==NULL)
			{
			printf("\n Tree is empty...");
			break;
			}
			postOrder(root);
			break;
		case 7: break;
		default: printf("Enter a valid choice...");
		}
	}while(c!=7);
}


st * insert(st *newnode,int i)
{
	if(newnode==NULL)
	{	
	newnode=(st*)malloc(sizeof(st));
	newnode->data=i;
	newnode->leftchild=newnode->rightchild=NULL;
	}
	else if (newnode->data==i)
	{
	printf("\nDuplicate Node...");
	}
	else if(i>newnode->data)
	{
	newnode->rightchild=insert(newnode->rightchild,i);
	}
	else if(i<newnode->data)
	{
	newnode->leftchild=insert(newnode->leftchild,i);
	}
	return (newnode);
}
struct node * newnode(int x)
{
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	if(p==NULL)
	{
	printf("Unable to allocate memory");
	exit(0);
	}
	p->data=x;
	p->leftchild=NULL;
	p->rightchild=NULL;
	return p;
}

st* delete(st*newnode,int d)
{
st*temp=newnode;
if(newnode==NULL)
{
printf("\n%d is not found",d);
}
else if(d>newnode->data)
{
newnode->rightchild=delete(newnode->rightchild,d);
}
else if(d<newnode->data)
{
newnode->leftchild=delete(newnode->leftchild,d);
}
else
{
if(newnode->leftchild==NULL && newnode->rightchild==NULL)
{
free(newnode);
newnode=NULL;
}
else if(newnode->leftchild==NULL)
{
newnode=newnode->rightchild;
free(temp);
}
else if(newnode->rightchild==NULL)
{
newnode=newnode->leftchild;
free(temp);
}
else
{
temp=delete_successor(newnode->rightchild);
newnode->data=temp->data;
newnode->rightchild=delete(newnode->rightchild,temp->data);
}
}
return newnode;
}
st*delete_successor(st*newnode)
{
while(newnode->leftchild!=NULL)
{
newnode=newnode->leftchild;
}
return newnode;
}


void search(st*newnode,int s)
{
if(newnode==NULL)
{
printf("%d is not present",s); 
return;
}
if(newnode->data==s)
{
printf("%d is present",s);
return;
}
else if(s>newnode->data)
{
search(newnode->rightchild,s);
}
else if(s<newnode->data)
{
search(newnode->leftchild,s);
}
}


void inOrder(st*newnode)
{
if(newnode==NULL)
{
return;
}
inOrder(newnode->leftchild);
printf("\t%d",newnode->data);
inOrder(newnode->rightchild);
}


void preOrder(st*newnode)
{
if(newnode==NULL)
{
return;
}
printf("\t%d",newnode->data);
preOrder(newnode->leftchild);
preOrder(newnode->rightchild);
}


void postOrder(st*newnode)
{
if(newnode==NULL)
{
return;
}
postOrder(newnode->leftchild);
postOrder(newnode->rightchild);
printf("\t%d",newnode->data);
}
