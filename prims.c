#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node_
{
	int vno;
	struct node_* next;
	int w;
}node;
typedef struct _vertex 
{
	node *adjlist; 
} vertex;
typedef vertex *graph;
typedef struct pque
{
	int key;
	int vertex;
}pq;
int parent(int i)
{
	return i/2;
}
int left(int i)
{
	return 2*i;
}
int right (int i)
{
	return 2*i+1;
}
void swap(pq *a,pq *b)
{
	pq p=*a;
	*a=*b;
	*b=p;
}
void min_heapify(pq A[],int i,int heapsize)
{
	int l=left(i);
	int r=right(i);
	int smallest;
	if(l<=heapsize&&A[r].key<A[i].key)
		smallest=r;
	else
		smallest=i;
	if(r<=heapsize&&A[smallest].key>A[l].key)
		smallest=l;
	if(i!=smallest)
	{	swap(&A[i],&A[smallest]);
		min_heapify(A,smallest,heapsize);
	}	
}
void build_heap(pq A[],int heapsize)
{
	for (int i = heapsize/2; i >0; --i)
	{
		min_heapify(A,i,heapsize);
	}
}
void heapsort(pq A[],int heapsize)
{
	build_heap(A,heapsize);
	for (int i = heapsize; i >0; --i)
	{
		swap(&A[i],&A[1]);
		heapsize--;
		min_heapify(A,1,i-1);
	}
}
void insertheap(pq A[],pq p,int* heapsize)
{
	(*heapsize)++;
	int i=*heapsize;
	A[*heapsize]=p;
	while(i>1&&A[i].key<A[parent(i)].key)
	{
		swap(&A[i],&A[parent(i)]);
		i=parent(i);
	}
	return;
}
pq extract(pq A[],int *heapsize)
{
	pq tmp=A[1];
	A[1]=A[*heapsize];
	(*heapsize)--;
	min_heapify(A,1,*heapsize);
	return tmp;
}
void mst(graph G,int v)
{
	pq *queue=(pq*)malloc((v+1)*sizeof(pq));
	pq *A=(pq*)malloc((v)*sizeof(pq));
	int parent[v],isvisit[v],heapsize=0;
	for(int i=0;i<v;i++)
	{
		A[i].key=INT_MAX;
		A[i].vertex=i;
		parent[i]=-1;
		isvisit[i]=0;
	} 
	A[0].key=0;
	insertheap( queue,A[0],&heapsize);
	while(heapsize>0)
	{
		pq u=extract(queue,&heapsize);
		isvisit[u.vertex]=1;
		node* tmp=G[u.vertex].adjlist;
		while(tmp!=NULL)
		{
			if(isvisit[tmp->vno]==0&&A[tmp->vno].key>tmp->w)
			{
				A[tmp->vno].key=tmp->w;
				insertheap( queue,A[tmp->vno],&heapsize);
				parent[tmp->vno]=u.vertex;
			}
			tmp=tmp->next;	
		}
		
	}
	for (int i = 0; i < v; ++i) 
       	 	printf("%d - %d\n", parent[i], i); 
	return ;
	
	
}
int main()
{
	int v,e,deg;
	node *tmp;
	printf("Enter the number of vertices and edges\n");
	scanf("%d%d",&v,&e);
	graph A=(graph)malloc(v*sizeof(vertex));
	for(int i=0;i<v;i++)	
	{
		A[i].adjlist=NULL;
	}
	printf("Enter the neighbors for each of the vertex\n");
	for(int i=0;i<v;i++)
	{
		printf("enter the degree of vertex %d :\n",i);
		scanf("%d",&deg);		
		printf("enter neighbours and weights\n");
		for(int j=0;j<deg;j++)
		{
			tmp=(node*)malloc(sizeof(node));
			printf("%d--",j);
			scanf("%d%d",&tmp->vno,&tmp->w);
			tmp->next=A[i].adjlist;
			A[i].adjlist=tmp;
		}
		
	}
	mst( A, v);
	
}
