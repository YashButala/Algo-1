#include<bits/stdc++.h>
using namespace std;
void bellno(int n)
{
	vector< vector<int> > bell;
	vector<int> tmp;int k=0;
	tmp.push_back(1);
	bell.push_back(tmp); 
	for(int i=1;i<=n;i++)
	{
		tmp.clear();
		tmp.push_back(bell[i-1][i-1]);
		for(int j=1;j<=i;j++)
		{
			 k=bell[i-1][j-1] + tmp[j-1];
			tmp.push_back(k);
		}
		bell.push_back(tmp);
	}
	for(int i=0;i<n;i++)
		cout<<bell[i][i]<<" ";
	return ;	
}
int main()
{
	int n;
	cin>>n;
	bellno(n);
	return 0;
}
