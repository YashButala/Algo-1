#include<iostream>
using namespace std;
int fib(int n )
{
	if(n==0)
		return 0;
	if(n==1)
		return 	1;
	else
	{
		int k=(n%2?(n+1)/2:n/2);
		if(n%2)
			return fib(k)*fib(k)+fib(k-1)*fib(k-1);
		return fib(k)*(fib(k)+2*fib(k-1));	
	}	

}
int main()
{
	int n;
	cin>>n;
	cout<<fib(n)<<endl;
	return 0;
}