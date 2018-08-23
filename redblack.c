#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	char color;
	struct node *p,*r,*l;
};
typedef struct node  node;
void right_rotate(node* y,node** root,node* nul)
{
	node* x=y->l;
	y->l=x->r;
	if(x->r!=nul)
		x->r->p=y;
	x->p=y->p;
	if(y->p==nul)
		*root=x;
	else if(y==y->p->r)
		y->p->r=x;
	else
		y->p->l=x;
	y->p=x;
	x->r=y;	
}
void left_rotate(node* x,node** root,node* nul)
{
	node* y=x->r;
	x->r=y->l;
	if(y->l!=nul)
		y->l->p=x;
	y->p=x->p;
	if(x->p==nul)
		*root=y;
	else if(x==x->p->l)
		x->p->l=y;
	else
		x->p->r=y;
	x->p=y;
	y->l=x;
	
}
node* color_insert(node* z,node* root,node* nul)
{
	while(z!=root&&z->p->color=='r')
	{	
		if(z->p->p->l==z->p)
		{
			if((z->p->p->r!=nul)&&(z->p->p->r->color=='r'))
			{
				z->p->p->r->color='b';
				z->p->color='b';
				z->p->p->color='r';
				z=z->p->p;
			}
			else
			{
				
				if(z==z->p->r)
				{
					z=z->p;
					left_rotate(z,&root,nul);
				}
				z->p->color = 'b';
				z->p->p->color = 'r';
				right_rotate(z->p->p,&root,nul);	
			}
		}
		else
		{
			if(z->p->p->l!=nul&&z->p->p->l->color=='r')
			{
				z->p->p->l->color='b';
				z->p->color='b';
				z->p->p->color='r';
				z=z->p->p;
			}
			else
			{
				if(z==z->p->l)
				{
					z = z->p;
					right_rotate(z,&root,nul);
				}
				z->p->color = 'b';
				z->p->p->color = 'r';
				left_rotate(z->p->p,&root,nul);	
			}
		}
	}
	root->color='b';
	return root;

}
node* insert(int key,node* root,node* nul)
{
	node* tmp;
	tmp=(node*)malloc(sizeof(node));
	tmp->l=tmp->r=tmp->p=nul;
	tmp->color='r';
	tmp->key=key;
	if(root==nul)
	{
		tmp->color='b';
		return tmp;
	}
	else
	{
		node *temp=root,*prev;
		while(temp!=nul)
		{
			prev=temp;
			if(temp->key>key)
				temp=temp->l;
			else if(temp->key<key)
				temp=temp->r;

		}
		if(key>prev->key)
			prev->r=tmp;
		else
			prev->l=tmp;
		tmp->p=prev;
		
		return color_insert(tmp,root,nul);	
	}
}
int computeBlackHeight(node* currNode,node* nul) 
{
    if (currNode == nul)
        return 0; 
    int leftHeight = computeBlackHeight(currNode->l,nul);
    int rightHeight = computeBlackHeight(currNode->r,nul);
    int add = currNode->color == 'b' ? 1 : 0;
    if (leftHeight == -1 || rightHeight == -1 || leftHeight != rightHeight)
        return -1; 
    else
        return leftHeight + add;
}

int main()
{
	node* root,*nul;
	nul=(node*)malloc(sizeof(node));
	nul->r=nul->l=nul->p=NULL;
	nul->color='b';
	nul->key=0;
	root=nul;
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int k;
		scanf("%d",&k);
		root =insert(k,root,nul);
//		printf("%d\n",root->key	 );
	}
	printf("%d\n",computeBlackHeight(root,nul) );
	return 0;
} 
