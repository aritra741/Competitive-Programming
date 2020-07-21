#include<bits/stdc++.h>
#define mx 200007
using namespace std;

int dp[mx][4];
int id[mx];

int main()
{
    int a,b,c;
    cin>>a>>b>>c;

    for( int i=0;i<a;i++ )
    {
        int x;
        cin>>x;

        id[x]= 1;
    }

    for( int i=0;i<b;i++ )
    {
        int x;
        cin>>x;

        id[x]= 2;
    }

    for( int i=0;i<c;i++ )
    {
        int x;
        cin>>x;

        id[x]= 3;
    }

    int n= a+b+c;

    for( int i=1;i<=n;i++ )
    {
        if( id[i]==1 )
        {
            dp[i][1]= dp[i-1][1];
            dp[i][2]= min( dp[i-1][1], dp[i-1][2] )+1;
            dp[i][3]= min( dp[i-1][1], min( dp[i-1][2], dp[i-1][3] ) )+1;
        }
        else if( id[i]==2 )
        {
            dp[i][1]= dp[i-1][1]+1;
            dp[i][2]= min( dp[i-1][2], dp[i-1][1] );
            dp[i][3]= min( dp[i-1][1], min( dp[i-1][2], dp[i-1][3] ) )+1;
        }
        else
        {
            dp[i][1]= dp[i-1][1]+1;
            dp[i][2]= min( dp[i-1][1], dp[i-1][2] )+1;
            dp[i][3]= min( dp[i-1][1], min( dp[i-1][2], dp[i-1][3] ) );
        }
    }

    cout<< min( dp[n][1], min( dp[n][2], dp[n][3] ) ) <<endl;
}
