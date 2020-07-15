#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    string s;

    while(cin>>s and s[0]!='0')
    {
        int n= s.size();
        ll arr[n+5], dp[n+5];
        arr[0]= 0;

        for( int i=1; i<=n; i++ )
            arr[i]= s[i-1]-'0';

        dp[0]=dp[1]= 1;

        for( int i=2; i<=n; i++ )
        {
            ll x= arr[i-1]*10+arr[i];
            ll y= 0;
            if(x>=10 and x<=26)
                x= dp[i-2];
            else
                x= 0;
            if( arr[i]!=0 )
                y= dp[i-1];

            if( x+y==0 and arr[i] )
                x= 1;

            dp[i]= x+y;
        }

        cout<< dp[n] <<endl;
    }
}
