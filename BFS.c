#include<stdio.h>
int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;
void bfs(int v) 
{
	for (i=0;i<n;i++)
	if(a[v][i] && !visited[i])
		q[++r]=i;
	if(f<=r)
	{
		visited[q[f]]=1;
		bfs(q[f++]);
	}
}
int main()
{
	int v,f=0;
	printf("\n Enter total number of vertices : ");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		q[i]=0;
		visited[i]=0;
	}
	printf("\n Enter elements in the form of adjacent matrix(1:Presence and 0:Absence) : ");
	for (i=0;i<n;i++)
	{
	for (j=0;j<n;j++)
	scanf("%d",&a[i][j]);
	}
	s:
	printf("\n Enter the source vertex : ");
	scanf("%d",&v);
	for(i=0;i<n;i++)
	{
	if(i==v)
	f=1;
	}
	if(f==1)
	{
	bfs(v);
	}
	else
	{
	printf("Please enter a valid source vertex..");
	goto s;
	}
	printf("\n The reachable vertices are : ");
	for (i=0;i<n;i++)
	{
	if(visited[i])
	printf("%d\t",i); 
	}
	printf("\n Others are unreachable vertices.If any...");
return 0;
}