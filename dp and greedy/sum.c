	#include<stdio.h>
#include<stdlib.h>
void fun(int n,int z1,int z2)
{
	int A[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&A[i]);		
	}
	if(n==1)
	{
		if(abs(z1)==abs(A[0])||abs(z2)==abs(A[0]))
		{	printf("1\n");return;}
	}
	if(n==2)
	{
		if(abs(z1)==abs(A[0])||abs(z2)==abs(A[0])||abs(z1)==abs(A[1])||abs(z2)==abs(A[1]))
			{printf("1\n");return;}
		if(z1==0||z2==0)
			{printf("2\n");return;}
	}
	printf("0\n");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,z1,z2;
		scanf("%d%d%d",&n,&z1,&z2);
		fun(n,z1,z2);
	}
}