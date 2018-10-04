#include<stdio.h>
#define max( a , b) (a>b ? a : b)
typedef struct job
{
	int start_time,end_time,weight;
}job;
void merge(job a[],int low ,int mid,int high)
{
	int i=low,j=mid+1;
	int k=0;
	job b[high-low+1];
	while(i<=mid&&j<=high)
	{
		if(a[i].end_time>a[j].end_time)
		{
			b[k]=a[j];
			j++;
			k++;
		}
		else
		{
			b[k]=a[i];
			i++;
			k++;
		}
	}
	while(i<=mid)
	{
		b[k]=a[i];
		i++;
		k++;
	}
	while(j<=high)
	{
		b[k]=a[j];
		j++;
		k++;
	}
	for(i=low,k=0;i<=high;i++,k++)
	{
		a[i]=b[k];
	}
	return ;
}
void mergesort(job a[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
void find(int P[],job A[],int n)
{
	P[0]=-1;
	int i,j=0;
	for(i=1;i<n;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(A[i].start_time>=A[j].end_time)
			{
				break;
			}
		}
		P[i]=j;	
	}
	
	for(int i=0;i<n;i++)
		printf("%d",P[i]);
	printf("\n");				
}
void wis(job A[],int n)
{
	mergesort(A,0,n-1);
	int P[n];
	find(P,A,n);
	int W[n+1];
	W[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(P[i-1]==-1)
			W[i]=max(W[i-1],A[i-1].weight);
		else		
			W[i]=max(W[i-1],W[P[i-1]+1]+A[i-1].weight);
	}
	printf("%d\n",W[n]);	
}
int main()
{
 	int n;
 	scanf("%d",&n);
 	job A[n];
 	for(int i=0;i<n;i++)
 		scanf("%d%d%d",&A[i].start_time,&A[i].end_time,&A[i].weight);
 	wis(A,n);	
}

