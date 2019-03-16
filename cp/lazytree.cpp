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
ll getSum(ll S[],ll lazy[],ll cur,ll node_l,ll node_r,ll l,ll r) 
{
	if(lazy[cur]!=0)
   	{
   		S[cur]+=(node_r-node_l+1)*lazy[cur];
   		lazy[right(cur)]+=lazy[cur];
   		lazy[left(cur)]+=lazy[cur];
   		lazy[cur]=0;
   	}
   	if(node_l>=l && node_r<=r)
   	{
   		return S[cur];
   	}
   	else if (node_r<l || r<node_l)
        return 0;
   	else
   	{
   		ll m=(node_l+node_r)/2;
		return getSum(S,lazy,left(cur),node_l,m,l,r) + getSum(S,lazy,right(cur),m+1,node_r,l,r);
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
void rangeUpdate(ll S[],ll lazy[],ll cur,ll l,ll r,ll range_l,ll range_r,ll diff)
{
	if(lazy[cur]!=0)
	{
		S[cur]+=(r-l+1)*lazy[cur];
		lazy[cur]=0;
		lazy[right(cur)]+=diff;
		lazy[left(cur)]+=diff;
	}
	if(l>r || range_l > r|| range_r < l)
	{
		return;	
	}
	else if(l>=range_l && r<= range_r)
	{
		S[cur]+=(r-l+1)*diff;
		lazy[right(cur)]+=diff;
		lazy[left(cur)]+=diff;
		return;
	}       
	else
	{
		ll m=(l+r)/2;
		rangeUpdate(S,lazy,left(cur),l,m,range_l,range_r,diff);
		rangeUpdate(S,lazy,right(cur),m+1,r,range_l,range_r,diff);
		S[cur]=S[left(cur)]+S[right(cur)];
	}
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
//	for(ll i=1;i<=tmp;i++)
//		cout<<Seg[i]<<endl;
//	cout<<getSum( Seg,1,0,n-1,1	,3)<<endl;
//	updateValue(Seg,n,A,1,10);
	ll lazy[tmp];
	for(ll i=1;i<=tmp;i++)
		lazy[i]=0;
	rangeUpdate(Seg,lazy,1,0,n-1,1,3,10);
	cout<<getSum(Seg,lazy,1,0,n-1,1,1)<<endl;
	return 0;	
}