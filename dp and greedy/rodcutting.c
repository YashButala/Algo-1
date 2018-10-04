#include<stdio.h>
#define max(a,b) ((a>b)?a:b)
int cut_rod(int p[],int n)
{
	int r[n+1];
	r[0]=0;
	for(int j=1;j<=n;j++)
	{
		int q=-1;
		for(int i=1;i<=j;i++)
		{
			q=max(q,p[i-1]+r[j-i]);
		}
		r[j]=q;
	}
	for(int i=1;i<n;i++)
		printf("%d\n",r[i]);
	return r[n];
	
}
int main()
{
	int n;
	scanf("%d",&n);
	int p[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	printf("%d\n",cut_rod(p,n));
	return 0;
}
