#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[100007][2];
ll c[100007];
string s[100007], rev[100007];

int main()
{
    memset( dp, 0x3f, sizeof(dp) );

    int n;
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>c[i];

    for(int i=0; i<n; i++)
    {
        cin>>s[i];
        string t= s[i];
        reverse( t.begin(), t.end() );
        rev[i]= t;
    }

    dp[0][0]= 0;
    dp[0][1]= c[0];

    for(int i=1; i<n; i++)
    {
        if( s[i-1]<=s[i] )
            dp[i][0]= min( dp[i][0], dp[i-1][0] );
        if( rev[i-1]<=s[i] )
            dp[i][0]= min( dp[i][0], dp[i-1][1] );
        if( s[i-1]<=rev[i] )
            dp[i][1]= min( dp[i][1], dp[i-1][0]+c[i] );
        if( rev[i-1]<=rev[i] )
            dp[i][1]= min( dp[i][1], dp[i-1][1]+c[i] );
    }

    if( dp[n-1][0]>=1e15 and dp[n-1][1]>=1e15  )
        cout<< "-1" <<endl;
    else
        cout<< min( dp[n-1][0], dp[n-1][1] ) <<endl;
}
