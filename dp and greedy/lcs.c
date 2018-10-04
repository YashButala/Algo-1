#include<stdio.h>
#include<string.h>
#define max(a,b) (a>b?a:b);
int LCS(const char  sa[],const char sb[])
{
	int an=strlen(sa),bn=strlen(sb);
	int a[an+1][bn+1];
	for(int i=0;i<=an;i++)
		for(int j=0;j<=	bn;j++)
		{
			if(i==0||j==0)
				a[i][j]=0;
			else if(sa[i-1]==sb[j-1])
				a[i][j]=a[i-1][j-1]+1;
			else
				a[i][j]=max(a[i-1][j],a[i][j-1]);	
					
		}	
	for(int i=0;i<=an;i++)
		for(int j=1;j<=bn;j++)
		{
			if(a[i][j]>a[i][j-1])
			{
				printf("%c",sa[i]);
				i++;
				j++;
			}	
		}
	return a[an][bn];	
}
int main() 
{ 
  char X[] = "AGGTAB"; 
  char Y[] = "GXTXAYB"; 
   
  printf("Length of LCS is %d\n", LCS( X, Y) ); 
  
  return 0; 
} 
