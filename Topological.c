#include<stdio.h>
int cost[10][10],indegree[10],n,i,j,k,count;
void cal()
{
	for(i=0;i<n;i++)
	{
		indegree[i]=0;
		for(j=0;j<n;j++)
	        indegree[i]+=cost[j][i];
	}
}
void sremoval()
{
	int removal[10]={0};
	printf("topo order:");
	for(count=0;count<n;count++)
	{
		cal();
		for(i=0;i<n;i++)
		{
			if(removal[i]==0 && indegree[i]==0)
			break;
		}
		if(i==n)
		{
			printf("graph is cyclic");
			return;
		}
		printf("%d\t",i);
		removal[i]=1;
		for(k=0;k<n;k++)
		 cost[i][k]=0;
}
}
int main()
{
	printf("enter no of vertices:");
	scanf("%d",&n);
	printf("enter matrix");
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d",&cost[i][j]);
	sremoval();
}
