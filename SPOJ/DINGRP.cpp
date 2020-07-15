#include <bits/stdc++.h>
using namespace std;

int dp[110][110][110];
bool vis[110][110][110];
int k;
string s;

int rec( int l, int r, int carry )
{
    if( l>r )
        return 0;
    if( vis[l][r][carry] )
        return dp[l][r][carry];

    int ans= 1000;
    if( carry>=k-1 )
        ans= 1+rec( l+1, r, 0 );

    for( int i=l+1;i<=r;i++ )
        if( s[i]==s[l] )
            ans= min( ans, rec( l+1, i-1, 0 )+rec( i, r, carry+1 ) );

    vis[l][r][carry]= 1;
    return dp[l][r][carry]= ans;
}

int main()
{
    int n;
    cin>>n>>k;

    cin>>s;

    int ans= rec( 0, n-1, 0 );

    if( ans<=n )
        cout<< ans <<endl;
    else
        cout<<"-1"<<endl;
}
