#include<stdio.h>
using namespace std;
bool isSubsetSum(int a[],int n,int sum	)
{
	bool subset[sum+1];
	for(int i=0;i<=sum;i++)
		subset[i]=false;
	int j;	
	for(int i=1;i<=n;i++)
	{
		subset[j]=true;
		for( j=sum;j>0;j--)
		{
			if(j>=a[i-1])
				subset[j]=(subset[j]||subset[j-a[i-1]]);
			else
				subset[j]=subset[j];	
		}
	}	
	return subset[sum];		
		
}
int main() 
{ 

  int set[] = {3, 34, 4, 12, 5, 2}; 
  int sum = 11; 
  int n = sizeof(set)/sizeof(set[0]); 
  if (isSubsetSum(set, n, sum) == true) 
     printf("Found a subset with given sum"); 
  else
     printf("No subset with given sum"); 
  return 0; 
} 
