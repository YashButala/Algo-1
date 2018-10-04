#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define M 7
struct cell
{
	int key;
	struct cell* next;
};
typedef struct cell cell,*p_cell;
int hash1(int key)
{
	return key%M;
}
bool search(p_cell a[],int key)
{
	int s=hash1(key);
	p_cell temp=a[s];
	while(temp!=NULL)
	{
		if(temp->key==key)
		{
			printf("found\n");
			return true;
		}
		else
			temp=temp->next;
	}
	printf("not found\n");
	return false;
}
void insert(p_cell a[],int key)
{
	if(search(a,key))
		return ;
	int hash=hash1(key);
	p_cell new=(p_cell)malloc(sizeof(cell));
	new->key=key;
	new->next=a[hash];
	a[hash]=new;
	return; 	
}
void print(p_cell a[])
{
	int i;
	printf("hash\n");
	for(i=0;i<M;i++)
	{
		if(a[i]==NULL)
			printf("NULL\n");
		else
		{
			p_cell tmp=a[i];
			while(tmp!=NULL)
			{
				printf("%d\t",tmp->key );
				tmp=tmp->next;
			}
			printf("\n");
		}
	}
}

void delete(p_cell a[],int key)
{
	int s=hash1(key);
	p_cell temp=a[s],prev=NULL;;
	while(temp!=NULL)
	{
		if(temp->key==key)
		{
			if(prev==NULL)
			{
				a[s]=temp->next;
				return;
			}
			prev->next=temp->next;
			free (temp);

			printf("deleted\n");
			return;
		}
		else
				prev=temp;
			temp=temp->next;

    }     printf("not found\n");

}
int main()
{
	int i;
	p_cell a[M];
	for (i = 0; i < M; ++i)
	{
		a[i]=NULL;
	}
	int flag=1;
	while(1)
	{
		int n;
		printf("enter the opteration key\n1)insert key\n2)search key\n3)delete\n4)print\n5)end\n ");
		scanf("%d",&n);
		switch (n)
		{
			int key;
			case 1:
				printf("enter key to be inserted\n");
				scanf("%d",&key);
				insert(a,key);
				break;
			case 2:
				printf("enter the key to be searched\n");
				scanf("%d",&key);
				search(a,key);
				break;
			case 3:
				printf("enter the key to be deleted\n");
				scanf("%d",&key);
				delete(a,key);
				break;
			case 4:
				printf("hash table:\n");
				print(a);
				break;
			case 5:
				flag=0;
				break;
		}
	}
		return 0;
}
