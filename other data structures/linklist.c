#include<stdio.h>
#include<stdlib.h>
struct TCS
{
	float share_price;
	struct TCS* next;
};
void display(struct TCS * front)
{
	struct TCS* move;
	move=front;
	while(move!=NULL)
	{
		printf("%f\n",move->share_price);
		move=move->next;
	}
}
struct TCS* insert(struct TCS* front)
{
	printf("enter position of element to be inserted\n");
	int n;
	scanf("%d",&n);
	printf("enter data \n");
	struct TCS *tcs,*move;
	tcs=(struct TCS*)malloc(sizeof(struct TCS));
	scanf("%f",&tcs->share_price);
	if(n==1)
	{		
		tcs->next=front;
		front=tcs;
		return front;
	}

	else
	{
		move=front;
		while(--n-1)
		{
			move=move->next;
			
		}
		tcs->next=move->next;
		move->next=tcs;
		return front;
	}
	
}
struct TCS* del(struct TCS* front)
{
	printf("enter the element no. to be deleted\n");
	int n;
	scanf("%d",&n);
	struct TCS* tcs,*move;
	if(n==1)
	{
		tcs=front;//printf("%f",front->share_price);
		front=front->next;//printf("%f",front->share_price);
		free(tcs);
		return front; 
	}
	else
	{
		move=front;
		while(--n-1)
			move=move->next;
		tcs=move->next;//printf("%f",tcs->share_price);
		move->next=tcs->next;
		free(tcs);	
		return front;
	}

}
int main()
{
	int i,n;
	printf("enter number of months\n");
	scanf("%d",&n);

	struct TCS *front=NULL,*end,*move;
	for(i=0;i<n;i++)
	{
		move=(struct TCS*)malloc(sizeof(struct TCS));
		
		scanf("%f",&move->share_price);
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
	front=insert(front);
	display(front);
	front=	del(front);
	display(front);
	return 0;
}
