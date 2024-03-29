#include<stdio.h>
int a[20][20],visited[20],n,i,j;
void dfs(int v)
 {
	visited[v]=1;
	for(i=1;i<=n;i++)
	if(a[v][i] && !visited[i]) 
	{
		printf("\n %d->%d",v,i);
		visited[i]=1;
		dfs(i);
	}
}
void main()
{
	int count=0;
	printf("\n Enter number of vertices:");
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		visited[i]=0;
		for (j=1;j<=n;j++)
		   a[i][j]=0;
	}
	printf("\n Enter the adjacency matrix:\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	   scanf("%d",&a[i][j]);
	dfs(1);
	printf("\n");
	for (i=1;i<=n;i++) {
		if(visited[i])
		   count++;
	}
	if(count==n)
	  printf("\n Connected graph");
	else
	  printf("\n Not connected graph");
}
