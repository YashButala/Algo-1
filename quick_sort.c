#include<stdio.h>
int partition(int a[],int low,int high)
{
	int t,pivot=a[low],i,j;
	i=low;
	j=high;
	while(i<j)
	{
		while(a[i]<=pivot&i<=high)i++;
		while(a[j]>pivot)j--;
		if(i<j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
			j--;
		}
	}
	t=a[j];
	a[j]=pivot;
	a[low]=t;
	return j;
}
void quicksort(int a[],int low,int high)
{
	if(high>low)
	{
		int p=partition(a,low,high);
		quicksort(a,low,p-1);
		quicksort(a,p+1,high);
		return;
	}
	else
		return;

}
int main()
{
	int i,n,t;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quicksort(a,0,n-1);
	for(i=0;i<n;i++)
		printf("%d",a[i]);
	return 0;
}