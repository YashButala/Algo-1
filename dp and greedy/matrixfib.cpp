#include<iostream>
using namespace std;
void mat_fib(int n)
{
	int x=1;
	int y=1;
	int z=1;
	int w=0;
	for(int i=2;i<n-1;i++)
	{
		int tx=x+z;
		int ty=x;
		int tz=z+w;
		int tw=z;
		x=tx;
		y=ty;
		z=tz;
		w=tw;
	}
	cout<<x<<endl;
	return;
}
int main()
{
	int n;
	cin>>n;
	mat_fib(n);
	return 0;
}