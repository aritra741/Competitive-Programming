#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        string s;
        cin>>s;

        ll ans= 1;

        for( int i=1;i<s.size();i++ )
        {
            if( abs( s[i]-s[i-1] )>=1 )
                ans=(ans*(abs( s[i]-s[i-1] )+1))%mod;
            else
                ans= (ans*25)%mod;
        }
        cout<<ans<<endl;
    }
}
