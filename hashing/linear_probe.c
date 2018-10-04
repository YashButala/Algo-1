#include<stdio.h>
#define M 10
int hash(int key)
{
	return key%10;
}
void insert(int a[],int track[],int key)
{
	int t=(hash(key)-1)%M,h=hash(key);
	while(h!=t)
	{
		if(track[h])
		{	
			a[h]=key;
			track[h]=0;
			return;
		}
		else
			h=(h+1)%M;
	}
	if(track[t])
		{
			a[t]=key;
			track[t]=0;
		}
	else
		printf("no place\n");


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
	int i;
	int t=hash(key);
	int j=(t-1)%M;
	while(j!=t)
	{
		if(track[t]==0&&a[t]==key)
		{
			printf("found\n");
			return;
		}
		else if(track[t]==1)
		{
			printf("not found\n");
			return;
		}
		else
		{
			t=(t+1)%M;
		}

	}
	if(track[j]==0 && a[j]==key)
		printf("founde\n");
	else
		printf("not founde\n");
}
void delete(int a[],int track[],int key)
{
	int i;
	int t=hash(key);
	int j=(t-1)%M;
	while(j!=t)
	{
		if(track[t]==0&&a[t]==key)
		{
			a[t]=-1;
			printf("deleted\n");
			return;
		}
		else if(track[t]==1)
		{
			printf("not found\n");
			return;
		}
		else
		{
			t=(t+1)%M;
		}
	}
	if(track[j]==0 && a[j]==key)
		a[j]=-1;
	else
		printf("not founde\n");	
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