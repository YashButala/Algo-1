#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n],i,t;
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		a[i]=t;
	}
	int swap=1;
	while(swap)
	{
		swap=0;
		for(i=0;i<n-1;i++)
		{
			if(a[i]>a[i+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
				swap++;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d",a[i]);
	return 0;
}