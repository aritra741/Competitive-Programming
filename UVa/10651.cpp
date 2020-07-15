#include<bits/stdc++.h>
using namespace std;

int dp[5000];
bool vis[5000];

int rec( int mask )
{
    if( vis[mask] )
        return dp[mask];

    int ret= 0;
    for( int i=0; i<12; i++ )
        if( mask&(1<<i) )
            ret++;

    for( int i=0; i<12; i++ )
    {
        int now= mask;
        if( mask&(1<<i) and mask&(1<<(i+1)) )
        {
            if( i+2<12 and !(mask&(1<<(i+2))) )
            {
                now^= (1<<i);
                now^= (1<<(i+1));
                ret= min( ret, rec( now|(1<<(i+2) )) );
                now= mask;
            }
            if( i-1>=0 and !( mask&(1<<(i-1)) ) )
            {
                now^= (1<<(i+1));
                now^= (1<<i);
                ret= min( ret, rec( now|(1<<(i-1) )) );
                now= mask;
            }
        }
    }

    vis[mask]= 1;

    return dp[mask]= ret;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        string s;
        cin>>s;

        int mask= 0;
        for( int i=0;i<12;i++ )
            if( s[i]=='o' )
                mask|= (1<<i);

        cout<< rec( mask ) <<endl;
    }
}
