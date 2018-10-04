#include<stdio.h>
#define max(a,b) (a>b?a:b)
int maxset(int a[][2],int n)
{
	int S[n+1][n+1];
	int c[n+1][n+1];
	for(int i=0;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			if(i==j)
				S[i][j]=0;
			else
			{
				S[i][j]=0;
				for(int k=i+1;k<j;k++)
				{
					if(a[k][1]<a[j][0]&&a[k][0]>a[i][0])
					{
						S[i][j]++;
					}
				}
			}	
		}
	for(int i=0;i<=n;i++)
		c[i][i]=0;
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<=n-l;i++)
		{
			int j=i+l;
			if(S[i][j]!=0)
			{
				int q=0;
				for(int k=i+1;k<j;k++)
				{	
						q=max(q,c[i][k]+c[k+1][j]+1);
				}
				c[i][j]=q;
			}
			else
			{
				c[i][j]=0;
			}	
		}
	}	
	return c[0][n];
}
void merge(int a[][2],int low ,int mid,int high)
{
	int i=low,j=mid+1;
	int k=0;
	int b[high-low+1][2];
	while(i<=mid&&j<=high)
	{
		if(a[i][1]>a[j][1])
		{
			b[k][0]=a[j][0];
			b[k][1]=a[j][1];
			j++;
			k++;
		}
		else
		{
			b[k][0]=a[i][0];
			b[k][1]=a[k][1];
			i++;
			k++;
		}
	}
	while(i<=mid)
	{
		b[k][0]=a[i][0];
		b[k][1]=a[i][1];
		i++;
		k++;
	}
	while(j<=high)
	{
		b[k][0]=a[j][0];
		b[k][1]=a[j][1];
		j++;
		k++;
	}
	for(i=low,k=0;i<=high;i++,k++)
	{
		a[i][0]=b[k][0];
		a[i][1]=b[k][1];
	}
	return ;
}
void mergesort(int a[][2],int low,int high)
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
	int a[20][2];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i][0],&a[i][1]);	
	}	
	mergesort(a,0,n-1);
	printf("%d",maxset(a,n));
	return 0; 
	
}
