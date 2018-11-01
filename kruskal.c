#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int n;
	struct node* parent;
}node;
struct dset
{
	int rank;
	node* p;
};

struct Edge 
{ 
    int src, dest,weight; 
}; 
struct Graph 
{ 
    int V, E; 
    struct Edge* edge; 
};    
struct Graph* createGraph(int V, int E) 
{ 
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) ); 
    graph->V = V; 
    graph->E = E; 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) ); 
    return graph; 
}  
node* findset(node* t)
{
	node* tmp=t;
	while(tmp->parent!=NULL)
		 tmp=tmp->parent;
	if(t!=tmp)
		t->parent=tmp;
	return 	tmp; 
}
void unionset(struct dset* subset, node* x,node* y)
{
	int xh=findset(x)->n;
	int yh=findset(y)->n;
	if((subset[xh].rank)<subset[yh].rank)
	{
		subset[xh].p->parent=subset[yh].p;
	}
	else
	{
		subset[yh].p->parent=subset[xh].p;
		if(subset[xh].rank==subset[yh].rank)
		{
			subset[xh].rank++;
		}
			
	}
	
}
void merge(struct Graph* G,int low ,int mid,int high)
{
	int i=low,j=mid+1;
	int k=0;
	struct Edge b[high-low+1];
	while(i<=mid&&j<=high)
	{
		if(G->edge[i].weight>G->edge[j].weight)
		{
			b[k]=G->edge[j];
			j++;
			k++;
		}
		else
		{
			b[k]=G->edge[i];
			i++;
			k++;
		}
	}
	while(i<=mid)
	{
		b[k]=G->edge[i];
		i++;
		k++;
	}
	while(j<=high)
	{
		b[k]=G->edge[j];
		j++;
		k++;
	}
	for(i=low,k=0;i<=high;i++,k++)
	{
		G->edge[i]=b[k];
	}
	return ;
}
void sort(struct Graph* G,int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		sort(G,low,mid);
		sort(G,mid+1,high);
		merge(G,low,mid,high);
	}
}
void KruskalMST(struct Graph* graph,node* address[100],struct dset subset[])
{
	sort(graph,0,graph->E-1);	
	int i=0,e=0;
	int v=graph->V;
	struct Edge result[v];
	node* findx,*findy;
	while(e<v-1)
	{
		
		struct Edge ed=graph->edge[i++];
		findx= findset(address[ed.src]);
		findy=findset(address[ed.dest]);
		if(findx->n!=findy->n)
		{
			unionset(subset,findx,findy);
			result[e++]=ed;
		}
		
	}
	for(int j=0;j<v-1;j++)
		printf("%d-----%d---->>%d\n",result[j].src,result[j].dest,result[j].weight);
	return;
}
int main()
{
	int v;
	scanf("%d",&v);
	struct dset* subset=(struct dset*)malloc(v*sizeof(struct dset));
	node* address[100];
	for(int i=0;i<v;i++)
	{
		node* tmp=(node*)malloc(sizeof(node));
		tmp->n=i;
		tmp->parent=NULL;
		address[i]=tmp;
		subset[i].p=tmp;
	} 
    	int V = 4;  // Number of vertices in graph 
    	int E = 5;  // Number of edges in graph 
    	struct Graph* graph = createGraph(V, E); 
  
  
    // add edge 0-1 
    	graph->edge[0].src = 0; 
    	graph->edge[0].dest = 1; 
    	graph->edge[0].weight = 10; 
  
    // add edge 0-2 
    	graph->edge[1].src = 0; 
    	graph->edge[1].dest = 2; 
    	graph->edge[1].weight = 6; 
  
    // add edge 0-3 
    	graph->edge[2].src = 0; 
    	graph->edge[2].dest = 3; 
    	graph->edge[2].weight = 5; 
  
    // add edge 1-3 
    	graph->edge[3].src = 1; 
    	graph->edge[3].dest = 3; 
    	graph->edge[3].weight = 15; 
  
    // add edge 2-3 
    	graph->edge[4].src = 2; 
    	graph->edge[4].dest = 3; 
    	graph->edge[4].weight = 4; 
 
    	KruskalMST(graph,address,subset); 
  
    	return 0; 
} 


