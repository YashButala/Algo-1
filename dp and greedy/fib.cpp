#include<iostream>
using namespace std;
void fib(int n)
{
	int *a=new int [n];
	a[0]=0;
	a[1]=1;
	cout<<0<<endl<<1<<endl;
	for(int i=2;i<n;i++)
	{
		a[i]=a[i-1]+a[i-2];
		cout<<a[i]<<endl;
	}
}
int main()
{
	int n;
	cin>>n;
	fib(n);
	return 0;
}