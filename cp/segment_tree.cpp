#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll right(ll i)
{
	return 2*i+1;
}
ll left(ll i)
{
	return 2*i;
}
ll parent(int i)
{
	return i/2;
}
ll construct(ll A[],ll S[], ll l,ll r,ll cur)
{
	if(l==r)
	{
		S[cur]=A[l];
	}
	else
	{
		ll m=(l+r)/2;
		S[cur]=construct(A,S,l,m,left(cur))+construct(A,S,m+1,r,right(cur));
	}
}
ll getSum(ll S[],ll cur,ll node_l,ll node_r,ll l,ll r) 
{
   if(node_l>=l && node_r<=r)
   		return S[cur];
   else if (node_r<l || r<node_l)
        return 0;
   else
   {
   		ll m=(node_l+node_r)/2;
		return getSum(S,left(cur),node_l,m,l,r) + getSum(S,right(cur),m+1,node_r,l,r);
   }
}
void updateSum(ll S[],ll cur,ll node_l,ll node_r,ll pos,ll diff) 
{
	if(node_l==node_r && node_l==pos)
	{
		S[cur]+=diff;
		return;
	}

   else if(node_l<=pos && node_r>=pos)
   {
   		S[cur]+=diff;
   		ll m=(node_l+node_r)/2;
		updateSum(S,left(cur),node_l,m,pos,diff);
		updateSum(S,right(cur),m+1,node_r,pos,diff);
   }	
   else
   {
   		return;
   }
}   
void updateValue(ll S[],ll n,ll A[],ll pos,ll val)
{
	if(pos>=0 && pos<=n-1) 
		updateSum(S,1,0,n-1,pos,val-A[pos]);
	else
		printf("invalid\n");		
}   
int main()
{
	ll n;
	cin>>n;
	ll A[n];
	for( ll i=0;i<n;i++)
	{
		cin>>A[i];
	}
	ll tmp=2*pow(2,ceil(log(n)/log(2)));
	cout<<tmp<<endl;
	ll Seg[tmp];
	for( ll i=0;i<=tmp;i++)
	{
		Seg[i]=-1;
	}
	Seg[1]=construct(A,Seg,0,n-1,1);
	for(ll i=1;i<=tmp;i++)
		cout<<Seg[i]<<endl;
//	cout<<getSum( Seg,1,0,n-1,1	,3)<<endl;
	updateValue(Seg,n,A,1,10);
	cout<<getSum(Seg,1,0,n-1,1,3)<<endl;
	return 0;	
}
