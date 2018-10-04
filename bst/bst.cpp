#include<iostream>
using namespace std;
struct TCS
{
	float share_price;
	TCS* left;
	TCS* right;
};
void preorder(TCS* root)
{
	if(root==NULL)
		return; 
	else
	{	
		cout<<root->share_price;
		
		preorder(root->left);
		preorder(root->right);
		
	}
}
void inorder(TCS* root)
{
	if(root==NULL)
		return; 
	else
	{	
		inorder(root->left);
		cout<<root->share_price;
		inorder(root->right);
		
	}
}
void postorder(TCS* root)
{
	if(root==NULL)
		return; 
	else
	{	
		postorder(root->left);
		postorder(root->right);
		cout<<root->share_price;
		
	}
}
int search(TCS* root,int key)
{
	if(root->share_price==key)
	{
		
		return 1;
	}
	if(root==NULL)
		return 0;	
	if(root->share_price>key)
		return search (root->left,key);
	if(root->share_price<key)
		return search (root->right,key);
				
}
int main()
{
	TCS* root,*move,*temp;
	int n;
	cout<<"enter the total elements of  bts\n";
	cin>>n;
	cout<<"enter root value"<<endl;
	root=new TCS;
	cin>>root->share_price;
	root->left=NULL;
	root->right=NULL;
	cout<<"enter remaining values\n";
	while(--n)
	{
		int flag=0;
		temp=new TCS;
		cin>>temp->share_price;
		temp->left=NULL;
		temp->right=NULL;
		move=root;
		while(1)
		{
			if(move->share_price>=temp->share_price)
			{
				
				if(move->left==NULL)
				{
					flag=1;
					break;
				}
				move=move->left;
								
			}
			else 
			{
				if(move->right==NULL)
				{
					flag=2;
					break;
				}
				move=move->right;
				flag=2;	
			}
			
		}
		if(flag==1)
			move->left=temp;
		if(flag==2)
			move->right=temp;	
	}
	cout<<"preorder traversal:::::\n";
	preorder(root);
	cout<<"\ninorder::::\n";
	inorder(root);
	cout<<"\npostorder\n";
	postorder(root);
	cout<<"\n"<<search(root,6);
	return 0;		
	
}
