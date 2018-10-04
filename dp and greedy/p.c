#include<iostream>
using namespace std;
void fun()
{
	int i,j,n,m,w_f=0,i_f=0;
	cin>>n>>m;
	char a[10],b[50];
	for(i=0;i<n;i++)
	{
		scanf("%s",a);
		scanf("%s",b);
		if(a=="correct")
		{
			for(int j=0;j<m;j++)
			{
				if(a[j]=='0')
					i_f=1;
			}
		}
		if(a=="wrong")
		{
			for(int j=0;j<m;j++)
			{
				if(a[j]=='0')
					w_f=1;
			}
			if(w_f)
				w_f=0;
			if(!w_f)
				w_f=1;
		}
	}
	if(i_f==1)
	{
		cout<<"INVALID\n";
		return;
	}
	if(w_f==1)
	{
		cout<<"WEAK\n";
		return;
	}
	cout<<"FINE\n";
	return;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		fun();
	}
	return 0;
	
}