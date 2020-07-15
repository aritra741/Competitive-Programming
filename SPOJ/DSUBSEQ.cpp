#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

ll dp[100007];
int vis[100007];

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        vector<int> last( 30,-1 );
        string s;
        cin>>s;

        dp[0]= 1;
        dp[1]= 2;
        last[ s[0]-'A' ]= 0;

        for( int i=2;i<=s.size();i++ )
        {
            dp[i]= (dp[i-1]*2)%mod;

            if( last[ s[i-1]-'A' ]!=-1 )
                dp[i]= (dp[i]+mod-dp[ last[ s[i-1]-'A' ] ])%mod;

            last[ s[i-1]-'A' ]= i-1;
        }

        cout<< dp[s.size()] <<endl;
    }
}
