#include<stdio.h>

int a[100],n,i,p,e;
void insert();
void display();

void main()
{
int c;
printf("\n Enter the array size : ");
scanf("%d",&n);
printf("\nEnter the elements one by one : ");
for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	}
printf("\nThe array elements are : ");
for(i=0;i<n;i++)
	{
	printf("%d\t",a[i]);
	}
printf("\n1.INSERT");
printf("\n2.DISPLAY");
printf("\n3.EXIT");
do
{
printf("\n\nEnter your choice : ");
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
display();
break;
}
case 3:return;
default:printf("\nYou entered invalid option");
}
}
while(c!=3);
}

void insert()
{
printf("\nEnter the position you want to insert : ");
scanf("%d",&p);
printf("Enter the element you want to insert : ");
scanf("%d",&e);
for(i=n-1;i>=p-1;i--)	
a[i+1]=a[i];
a[p-1]=e;
n++;
printf("The array after insertion is : ");
for(i=0;i<=n-1;i++)
printf("%d\t",a[i]);
}

void display()
{

printf("The array is : ");
for(i=0;i<=n-1;i++)
printf("%d\t",a[i]);
}