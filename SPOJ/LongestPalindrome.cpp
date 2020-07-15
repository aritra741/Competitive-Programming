#include <bits/stdc++.h>
using namespace std;

int dp[1010][1010];
bool vis[1010][1010];
string s;

int rec( int l, int r )
{
    if(l>r)
        return 0;
    if(l==r)
        return 1;
    if(vis[l][r])
        return dp[l][r];

    int q1,q2=0;

    if(s[l]==s[r])
        q1= 2+ rec( l+1, r-1 );
    else
    {
        q1= rec( l, r-1 );
        q2= rec( l+1, r );
    }

    vis[l][r]= 1;

    return dp[l][r]= max( q1,q2 );
}

int main()
{
    int tc;
    cin>>tc;
    getchar();

    while(tc--)
    {
        getline(cin,s);

        if(s.size())
            cout<< rec( 0, s.size()-1 ) <<endl;

        else
            cout<<"0\n";

        memset( vis, 0, sizeof(vis) );
    }
}
