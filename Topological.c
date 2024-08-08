#include<stdio.h>
#include<stdlib.h>
int indegree[10],cost[10][10],n;
void cal()
{
	int i,j;
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
	int i,k,count;
	printf("sprting order\n");
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
			printf("graph is cyclic no sol\n");
			return;
		}
		printf("%d\t",i);
		removal[i]=1;
		for(k=0;k<n;k++)
		 cost[i][k]=0;
	}
	printf("above is the correct sol\n");
}
int main()
{
	int i,j;
	printf("enter no. of verticces\n");
	scanf("%d",&n);
	printf("enter matrix\n");
	for(i=0;i<n;i++)
	 for(j=0;j<n;j++)
	  scanf("%d",&cost[i][j]);
	sremoval();  
}
