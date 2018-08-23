#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
typedef struct node node;
node* insert(node* root,int k)
{
	node *key,*prev;
	
	key=(node*)malloc(sizeof(node));
	key->data=k;
	key->left=key->right=NULL;
	if(root==NULL)
	{
		root=key; 
		return root;		
	}
	else
	{
		node* temp=root;	
		while(temp!=NULL)
			{
				prev=temp;
				if(k>temp->data)
					temp=temp->right;
				else 
					temp=temp->left;
							
			}
		
			if(k>prev->data)
				prev->right=key;
			else
				prev->left=key;
			return root;
	}
				
}
void delete(node*root,int k )
{
	node* temp=root,*prev;	
	while(temp!=NULL)
	{
			
			if(k>temp->data)
			{
				prev=temp;
				temp=temp->right;
			}
			else if(k<temp->data)
			{	
				prev=temp;
				temp=temp->left;
			}
			else
				break;
									
	}
	if(temp==NULL)
		return;
	if(temp->right==NULL&&temp->left==NULL)
	{
		if(temp==prev->right)
		{
			prev->right=NULL;
			free(temp);
		}
		else
		{
			prev->left=NULL;
			free(temp);	
		}
		return;
	}
	if(temp->right==NULL)
	{
		if(prev->left==temp)
		{
			prev->left=temp->left;
			free(temp);
		}
		else
		{
			prev->right=temp->left;
			free(temp);
		}	
		return ;

	}
	if(temp->left==NULL)
	{
		
		if(prev->left==temp)
		{
			prev->left=temp->right;
			free(temp);
		}
		else
		{
			
			prev->right=temp->right;
			free(temp);
		}	
		return ;

	}
	{
		node *temp2,*prev2=NULL;
		prev2=temp2=temp->right;
		while(temp2->left!=NULL)
		{
				prev2=temp2;
			temp2=temp2->left;
		}
		temp->data=temp2->data;
		if(prev2==temp2)
		{
			temp->right=temp2->right;
			free(temp2);
			return;
		}
		if(temp2->right==NULL)
		{
			free(temp2);
			return ;
		}
		{
			prev->left=temp2->right;
			free(temp2);
			return;
		}
	}

}
struct stack
{
	node* p;
	struct stack *next;
};
typedef struct {
	struct stack *head ;
} STACK ;
void init(STACK *s)
{
	s->head=NULL;
}
int isempty(STACK *s)
{
	if(s->head==NULL)
		return 1;
	else
		return 0;
}
void push(STACK *s,node* data)
{
	struct stack*temp;
	temp=(struct stack*)malloc(sizeof( struct stack));
	temp->p=data;
	temp->next=s->head;
	s->head=temp;
}
node* pop(STACK *s)
{
	if(s->head==NULL)
		return NULL;
	struct stack* tmp=s->head;
	s->head=s->head->next;
	return tmp->p;
}
void preorder(node* root)
{
	STACK *s;
	s=(STACK *)malloc(sizeof(STACK));
	init(s);
	push(s,root);
	node* temp=root;
	
	while(!isempty(s)||temp!=NULL)
	{
		if(temp!=NULL)
		{
			while(temp->left!=NULL)
			{
				temp=temp->left;
				push(s,temp);
			}
			temp=pop(s);
			printf("%d\n",temp->data );
		}
		if(temp->right!=NULL)
		{
			temp=temp->right;
		}	
		
	}

}
int main()
{
//	printf("hi\n");
	node* root=NULL;
	root=insert(root,3);	 
	root=insert(root,1);	 
	root=insert(root,5);	 
	root=insert(root,6);
//	printf("%d",root->right->right->data);
//	delete(root,3);	 
	preorder(root);	
	return 0;
}
