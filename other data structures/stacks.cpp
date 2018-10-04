#include<iostream>
using namespace std;
struct TCS
{
	float share_price;
	struct TCS* next;
};
TCS* front;
void display()
{
	TCS* move=front;
	while(move!=NULL)
	{

		cout<<move->share_price<<endl;
		move=move->next;
	}
}
void push()
{
	cout<<"enter the share price\n";
	TCS* move;
	move=new TCS;
	cin>>move->share_price;
	move->next=front;
	front=move;
}
void pop()
{
	TCS* move=front;
	front=front->next;
	cout<<"pop element="<<move->share_price<<endl;
	delete move;
}
int main()
{
	int i,n;
	cout<<"enter number of months\n";
	cin>>n;
	front=NULL;
	TCS *move;
	for(i=0;i<n;i++)
	{
		move=new TCS;
		
		cin>>move->share_price;
		move->next=NULL;
		if(front==NULL)
		{

			front=move;
		}
		else
		{
			move->next=front;
			front=move;	
		}
		
				
	}
//	display(front);
	push();
	display();

	pop();
//	pop(front,end);
	display();
	return 0;
}
