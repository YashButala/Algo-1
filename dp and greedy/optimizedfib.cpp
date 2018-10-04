#include<iostream>
using namespace std;
int fib(int n)
{
	int tmp1=0;
	int tmp2=1;
	for(int i=2;i<n;i++)
	{
			tmp2=tmp1+tmp2;
			tmp1=tmp2-tmp1;
	}
	return tmp2;
}
int main()
{
	int n;
	cin>>n;
	cout<<fib(n);
	return 0;
}