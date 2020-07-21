#include<bits/stdc++.h>
using namespace std;

int dp[507][507];
bool vis[507][507];
string s;

int rec( int l, int r )
{
    if(l>r)
        return 0;
    if(l==r)
        return 1;
    if( vis[l][r] )
        return dp[l][r];

    int ret= 1+rec(l+1,r);

    for( int i=l+1;i<=r;i++ )
        if( s[i]==s[l] )
            ret= min( ret, rec( l+1, i-1 )+rec( i, r ) );

    vis[l][r]= 1;

    return dp[l][r]= ret;
}

int main()
{
    int n;
    cin>>n;
    cin>>s;

    cout<< rec( 0, n-1 ) <<endl;
}
