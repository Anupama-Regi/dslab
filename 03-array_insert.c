#include<stdio.h>
void main()
{
	int a[100],n,i,p,e;
	printf("\nEnter array size : ");
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
	printf("\nEnter the element you want to insert : ");
	scanf("%d",&e);
	printf("\nEnter the position you want to insert : ");
	scanf("%d",&p);
	if(p>n+1 || p<=0)
		{
			printf("Please enter a valid position..");
		}
	else
		{
			for(i=n;i>=p-1;i--)	
			a[i+1]=a[i];
			a[i+1]=e;
			n++;
			printf("The array after insertion is : ");
			for(i=0;i<n;i++)
			printf("\t%d",a[i]);
		}
}