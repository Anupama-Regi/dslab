#include<stdio.h>
int a[100],n,i,p;
void delete();
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
printf("\n1.DELETE");
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
delete();
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

void delete()
{
	if(n==0)
	{
		printf("Array is empty..");
	}
	else
	{
		printf("\nEnter the position you want to delete : ");
		scanf("%d",&p);
		if (p>n || p<=0)
		{
			printf("Please enter a valid position..");
		}
		else
		{
			printf("Element deleted is : %d",a[p-1]);
			for(i=p-1;i<n-1;i++)	
			a[i]=a[i+1];
		
		n--;
		}
	}
}

void display()
{
if(n==0)
{
printf("Array is empty..");
}
else
{
printf("The array is : ");
for(i=0;i<=n-1;i++)
printf("%d\t",a[i]);
}
}