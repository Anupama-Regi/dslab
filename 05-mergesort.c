#include<stdio.h>
#include<conio.h>
void main()
{
int ar1[10],ar2[10],n,m,t,i,ar3[20],k=0,j,temp;
printf("\nEnter the total number of elements in array1 : ");
scanf("%d",&n);
printf("\nEnter the elements one by one : ");
for(i=0;i<n;i++)
{
scanf("%d",&ar1[i]);
}
printf("\nElements of array1 are : ");
for(i=0;i<n;i++)
{
printf("\t%d",ar1[i]);
}
printf("\nEnter the total number of elements in array2 : ");
scanf("%d",&m);
printf("\nEnter the elements one by one : ");
for(i=0;i<m;i++)
{
scanf("%d",&ar2[i]);
}
printf("\nElements of array2 are : ");
for(i=0;i<m;i++)
{
printf("\t%d",ar2[i]);
}
t=n+m;
for(i=0;i<n;i++)
{
ar3[i]=ar1[i];
}
for(j=0;j<m;j++)
{
ar3[i]=ar2[j];
i++;
}
printf("\n\n Merged array : ");
for(i=0;i<t;i++)
{
printf("\t%d",ar3[i]);
}

for(i=0;i<t;i++)
{
for(j=i+1;j<t;j++)
{
if(ar3[i]>ar3[j])
{
temp=ar3[i];
ar3[i]=ar3[j];
ar3[j]=temp;
}
}
}
printf("\n\n Array after merge and sort : ");
for(i=0;i<t;i++)
{
printf("\t%d",ar3[i]);
}
getch();
}