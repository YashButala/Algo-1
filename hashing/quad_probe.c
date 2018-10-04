#include<stdio.h>
#define M 10
int hash(int key,int j)
{
	return (key+j*j)%10;
}
void insert(int a[],int track[],int key)
{
	int i=hash(key,0);
	int j=0;
	while(track[hash(i,j)]==0)
	{
		j++;
	}
	a[hash(i,j)]=key;
	track[hash(i,j)]=0;
}
void print(int a[],int track[])
{
	int i;
	for(i=0;i<M;i++)
	{
		if(!track[i])
			printf("%d++++",a[i] );
		else
			printf("NULL++++");
	}
}
void search(int a[],int track[],int key)
{
	int i=hash(key,0);
	int j=0;
	while(track[hash(i,j)]==0)
	{
		if(a[hash(i,j)]==key)
		{
			printf("found\n");
			return; 
		}
		j++;
	}
	printf("not found\n");	
	
}
void delete(int a[],int track[],int key)
{
	int i=hash(key,0);
	int j=0;
	while(track[hash(i,j)]==0)
	{
		if(a[hash(i,j)]==key)
		{
			printf("found and deleted\n");
			a[hash(i,j)]=-1;
			return; 
		}
		j++;
	}
}
int main()
{
	int i,a[M],track[M];
	for(i=0;i<M;i++)
	{
		a[i]=-1;
		track[i]=1;
	}
	int n;
	scanf("%d",&n);
	int key;
	while(n--)
	{
		
		scanf("%d",&key);
		insert(a,track,key);
	}
	print(a,track);
	int p,q;
	scanf("%d",&q);
	delete(a,track,q);
	scanf("%d",&p);
	search(a,track,p);
	
	return 0;
}