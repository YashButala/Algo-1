#include<stdio.h>
void merge(int a[],int low ,int mid,int high)
{
	int i=low,j=mid+1;
	int k=0;
	int b[high-low+1];
	while(i<=mid&&j<=high)
	{
		if(a[i]>a[j])
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
void mergesort(int a[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
int main()
{
	int i,t,n;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	mergesort(a,0,n-1);
	for(i=0;i<n;i++)
		printf("%d\n",a[i] );		
}