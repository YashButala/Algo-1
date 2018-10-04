#include<stdio.h>
int partition(int a[],int low,int high)
{
	int t,t1=0,t2=0,pivot=a[low],i;
	i=low+1;
	int temp_low[high-low+1];
	int temp_high[high-low+1];
	while(i<=high)
	{
		if(a[i]<pivot)
		{
			temp_low[t1]=a[i];
			t1++;
		}
		else
		{
			temp_high[t2]=a[i];
			t2++;
		}
		i++;
	}
	for(i=low;i<low+t1;i++)
		a[i]=temp_low[i-low];
	a[i]=pivot;
	for(i=low+t1+1;i<=high;i++)
		a[i]=temp_high[i-low-t1-1];		
	return t1+low;
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
