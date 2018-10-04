#include<stdio.h>
#include<stdlib.h>
void merge(int a[],int aa[],int low ,int mid,int high)
{
	int i=low,j=mid+1;
	int k=0;
	int b[high-low+1];
	int bb[high-low+1];
	while(i<=mid&&j<=high)
	{
		if(a[i]>a[j])
		{
			b[k]=a[j];
			bb[k]=aa[j];
			j++;
			k++;
		}
		else
		{
			b[k]=a[i];
			bb[k]=aa[i];
			i++;
			k++;
		}
	}
	while(i<=mid)
	{
		b[k]=a[i];
		bb[k]=aa[i];
		i++;
		k++;
	}
	while(j<=high)
	{
		b[k]=a[j];
		bb[k]=aa[j];
		j++;
		k++;
	}
	for(i=low,k=0;i<=high;i++,k++)
	{
		a[i]=b[k];
		aa[i]=bb[k];
	}
	return ;
}
void mergesort(int a[],int aa[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergesort(a,aa,low,mid);
		mergesort(a,aa,mid+1,high);
		merge(a,aa,low,mid,high);
	}
}
int selectactivity(int start[],int finish[],int n)
{
	int count=0;
	printf("%d\t%d\n",start[0],finish[0]);
	for(int i=1;i<n;i++)
	{
		if(start[i]>finish[count])
		{
			printf("%d\t%d\n",start[i],finish[i]);
			count++;
		}
		
	}
	return ++count;
}
int main()
{
	int n;
	printf("enter n:");
	scanf("%d",&n);
	printf("\n");
	int *start=(int*)malloc(n*sizeof(int));
	int *finish=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		scanf("%d",&start[i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&finish[i]);
	}
	mergesort(finish,start,0,n-1);
/*	for(int i=0;i<n;i++)
	{
		printf("%d  %d\n",start[i],finish[i]);
	}*/
	printf("max possibe activities is %d\n",selectactivity(start,finish,n));
	return 0;
}
