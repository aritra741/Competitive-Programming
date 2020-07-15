#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

int arr[510];
int dp[510][510];
int vis[510][510];
int p= 1;

int rec( int l, int r )
{
    if(l>r)
        return inf;
    if(l==r)
        return 1;
    if(r==l+1)
    {
        if(arr[l]==arr[r])
            return 1;
        return 2;
    }

    if( vis[l][r]==p )
        return dp[l][r];

    int ans= inf;

    if( arr[l]==arr[r] )
        ans= rec( l+1, r-1 );
    for(int i=l; i<r; i++)
    {
        if( arr[l]==arr[i] )
            ans= min( ans, rec( l,i )+rec(i+1,r) );
        else if( arr[r]==arr[i] )
            ans= min( ans, rec( l,i-1 )+rec( i,r ) );
    }

    vis[l][r]= p;

    return dp[l][r]= ans;
}

int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<< rec( 0, n-1 ) <<endl;
}
