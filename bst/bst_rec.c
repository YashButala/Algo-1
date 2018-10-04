#include <stdio.h>
#include<stdlib.h>
struct node
{
	struct node* left;
	struct node *right;
	int data;
};
typedef struct node node;
void init(node** root,int k)
{
	
	(*root)->data=k;
	(*root)->left=NULL;
	(*root)->right=NULL;
}
node* insert(node* root,int data)
{
	if(root==NULL)
	{
		node* tmp=(node*)malloc(sizeof(node));
		tmp->data=data;
		tmp->left=tmp->right=NULL;
		return tmp;
	}
	else if(data<root->data)
		root->left=insert(root->left,data);
	else
		root->right=insert(root->right,data);
	return root;

}
node * min(node* root)
{
    node* current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
}
node * max(node* root)
{
    node* current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
}
node* delete(node* root, int key)
{
    if (root == NULL) return root;
    if (key < root->data)
        root->left = delete(root->left, key);
    else if (key > root->data)
        root->right = delete(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        node* temp = min(root->right);
        root->data= temp->data;
        root->right=delete(root->right, temp->data);
    }
    return root;
}
void preorder(node* root)
{
	if(root==NULL)
		return;
	printf("%d\t",root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(node* root)
{
	if(root==NULL)
		return ;
	inorder(root->left);
	printf("%d\t",root->data );
	inorder(root->right);
}
void postorder(node* root)
{
	if(root==NULL)
		return ;
	postorder(root->left);
	postorder(root->right);
	printf("%d\t",root->data );
}
int main()
{
	node * root;
	
	root=(node*)malloc(sizeof(node));
	init(&root,5);printf("%p\n",root );
	root=insert(root,6);//printf("%d\n",root->right->data);
	root=insert(root,7);//printf("%p\n",root );
	root=insert(root,1);//printf("%p\n",root );
	root=insert(root,3);//printf("%p\n",root );printf("%d\n",root->left->right->data );
	root=delete(root,5);//printf("%p\n",root );
	root=insert(root,9);
	root=insert(root,8);
	root=insert(root,4);
	root=insert(root,2);
//	printf("%p\n",root );
	preorder(root);	
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
//	printf("%d\n",root->data );
	return 0;
}
