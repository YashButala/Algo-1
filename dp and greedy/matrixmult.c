#include<stdio.h>
void matrix_chainorder(int p[],int n,int m[][50],int s[][50])
{
	for(int i=1;i<=n;i++)
		m[i][i]=0;
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i<=n-l+1;i++)
		{
			int j=i+l-1;
			m[i][j]=10000;
			for(int k=i;k<j;k++)
			{
				int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{				
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}	
	
}
void print(int s[][50],int i,int j)
{

	if(i==j)
		printf("A%d",i);
	else
	{
		printf("(");
		print(s,i,s[i][j]);
		print(s,s[i][j]+1,j);
		printf(")");
	}	
}
int main()
{
	int n;
	scanf("%d",&n);	
	int p[n+1];
	for(int i=0;i<=n;i++)
		scanf("%d",&p[i]);
	int m[50][50],s[50][50];
	matrix_chainorder(p, n,m,s);
	print(s,1,n);	
	return 0;		
	
}
