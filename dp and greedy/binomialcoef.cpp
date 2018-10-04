#include<iostream>
#include<vector>
using namespace std;
int  bicoef(int n,int k)
{
	int j;
	vector< vector<int> > binomial;
	vector <int> tmp;
	tmp.push_back(1);
	binomial.push_back(tmp);
	for(int i=1;i<=n;i++)
	{
		tmp.clear();
		for( j=0;j<=min(i,k);j++)
		{
			if(j==0||j==i)
				tmp.push_back(1);
			else	
				tmp.push_back(binomial[i-1][j-1]+binomial[i-1][j]);
		}
		binomial.push_back(tmp);
	}
/*	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
			cout<<binomial[i][j]<<" ";
		cout<<endl;	
	}*/
	return binomial[n][k];	
}
int main()
{
	 int n,k;
	 cin>>n>>k;
	 cout<<bicoef(n,k);
	 return 0;
}
