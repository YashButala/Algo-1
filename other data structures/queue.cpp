#include<iostream>
using namespace std;
struct TCS
{
	float share_price;
	struct TCS* next;
};
void display(struct TCS * front)
{
	cout<<"the queue is:\n";
	struct TCS* move;
	move=front;
	while(move!=NULL)
	{
		cout<<move->share_price<<"\n";
		move=move->next;
	}
	cout<<endl;
}
TCS* enque(TCS *front)
{
	cout<<"enter the next element"<<endl;
	TCS* move=new TCS,*temp;
	cin>>move->share_price;
	move->next=NULL;
	if(front==NULL)
	{
		front =move;
		return front ;
	}
	else
	{
		temp=front;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=move;
		return front;	
	}		
}
TCS* deque(TCS *front)
{
	if(front==NULL)
		return NULL;

	TCS* move=front;
	front=move->next;
	delete move;
	return front;
}
int main()
{
	int i,n;
	cout<<"enter number of months\n";
	cin>>n;

	struct TCS *front=NULL,*end,*move;
	for(i=0;i<n;i++)
	{
		move=new TCS;
		
		cin>>move->share_price;
		move->next=NULL;
		if(front==NULL)
		{

			front=move;
			end=front;
		}
		else
		{
			end->next=move;
			end=move;	
		}
		
				
	}
	display(front);
	front =enque(front);
	display(front);
	front=deque(front);
	display(front);
	return 0;
}
