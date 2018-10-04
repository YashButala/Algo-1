#include<stdio.h>
#include<stdlib.h>
#include <math.h>
void count_sort(int a[],int n,int j)
{
	int c[10],i,b[n];
	for(i=0;i<10;i++)
		c[i]=0;
	int tmp=pow(10,j);
	for(i=0;i<n;i++)
		c[(a[i]/tmp)%10]++;
	for(int i=1;i<10;i++)
		c[i]+=c[i-1];

	for(i=n-1;i>=0;i--)
	{
		b[c[(a[i]/tmp)%10]-1]=a[i];
		c[(a[i]/tmp)%10]--;
	}
	for(i=0;i<n;i++)
		a[i]=b[i];

}
void radix(int a[],int n)
{
	for(int i=0;i<6;i++)
		count_sort(a,n,i);
}
int main()
{
	int i,n,t;
	scanf("%d",&n);
	int *a;
	a=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		a[i]=t;
	}
	radix(a,n);
	for(i=0;i<n;i++)
		printf("%d\n",a[i] );
	return 0;

}