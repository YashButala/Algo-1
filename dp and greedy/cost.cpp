#include <bits/stdc++.h>

using namespace std;

// Complete the cost function below.
int cost(vector<int> B) {
    vector<int> L,H;
    L.push_back(1);
    H.push_back(B[0]);
   // F.push_back(max(L[0],H[0]));
    for(int i=1;i<B.size();i++)
    {
        L.push_back(max(L[i-1],H[i-1]+abs(B[i-1]-1)));
        H.push_back(max(H[i-1]+abs(B[i]-B[i-1]),L[i-1]+abs(B[i]-1)));
    }
    return max(L[B.size()-1],H[B.size()-1]);
}

int main()
{
    int t,n,m;
    cin>>t;
    vector<int> B;
    while(t--)
    {
        B.clear();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int m;
            cin>>m;
            B.push_back(m);
        }
        cout<<cost(B)<<endl;
    }
} 
