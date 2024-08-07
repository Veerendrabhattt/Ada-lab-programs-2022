#include<stdio.h>
#include<stdlib.h>
 int count=0;
int partition(int a[],int l,int r)
{
	int p=a[l],i=l,j=r+1,temp;
	do
	{
		do
		{
			i++;
			count++;
		}while(i<r && a[i]<p);
		do
		{
			j--;
			count++;
		}while(j>l && a[j]>p);
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	while(i<j);
	temp=a[l];
	a[l]=a[j];
	a[j]=temp;
	return j;
}
void quick(int a[],int l,int r)
{
	int s;
	if(l<r)
	{
		s=partition(a,l,r);
		quick(a,l,s-1);
		quick(a,s+1,r);
	}
}
void main()
{
	int *a,n,i;
	printf("enter n:");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	 a[i]=rand()%1001;
	quick(a,0,n-1);
	printf("array ele\n");
	for(i=0;i<n;i++)
	 printf("%d\t",a[i]);
	printf("\nboc=%d",count);
	free(a);  
}
