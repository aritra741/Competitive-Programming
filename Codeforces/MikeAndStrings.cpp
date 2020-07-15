#include <bits/stdc++.h>
using namespace std;

string dp[55][2];
bool f;
int cnt;

int main()
{
    int n;
    cin>>n;

    if(n==1)
       return cout<<"0\n", 0;

    for( int i=0;i<n;i++ )
    {
        string s;
        cin>>s;

        string t;
        for( int i=1;i<s.size();i++ )
            t.push_back(s[i]);
        t.push_back( s[0] );

        dp[i][0]= s;
        dp[i][1]= t;

        if( i==n-1 )
            continue;

        f|= ( s==dp[i-1][0] or s==dp[i-1][1] );

        if( s!=dp[i-1][0] and s==dp[i-1][1] )
            cnt++;
    }

    if( f )
        cout<< cnt <<endl;
    else
        cout<< "-1" <<endl;
}
