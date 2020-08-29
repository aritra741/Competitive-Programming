#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;
ll dp[70][70];
int vis[70][70];
int p;

ll rec( int l, int r )
{
    if( l==r )
        return 1;
    if(l>r)
        return 0;
    if(vis[l][r]==p)
        return dp[l][r];

    ll q1= 0, q2= 0, q3= 0, q4= 0,q5= 0;

    if( s[l]==s[r] )
    {
        q1= rec( l+1,r );
        q2= rec( l,r-1 );
        q1++;
    }
    else
    {
        q2= rec( l+1, r );
        q3= rec( l, r-1 );
        q5= rec(l+1,r-1);
    }

    vis[l][r]= p;
    return dp[l][r]= q1+q4+q2+q3-q5;
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        p++;
        cin>>s;

        cout<<"Case "<<t<<": "<< rec( 0, s.size()-1 ) <<endl;
    }
}
