#include<iostream>
using namespace std;
void fun(int n,int m)
{
	int w_f=0,i_f=0,wf=0;
	string a,b;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		cin>>b;
		if(a=="correct")
		{
			for(int j=0;j<m;j++)
			{
				if(b[j]=='0')
				{
					i_f=1;
					break;
				}	
			}
		}
		if(a=="wrong"&&w_f==0)
		{
			wf=1;
			int flag=0;
			for(int j=0;j<m;j++)
			{
				if(b[j]=='0')
					flag=1;
			}
			if(flag==0)
				w_f=1;
		}
	}
	if(i_f)
	{
		cout<<"INVALID\n";
		return;
	}
	if(wf==1&&w_f==1)
	{	cout<<"WEAK\n";return;}
	
	cout<<"FINE\n";
	return;
}
int main()
{
	int t;
	cin>>t;
	int n,m;
	while(t--)
	{
		cin>>n>>m;
		fun(n,m);
	}
	return 0;
	
}