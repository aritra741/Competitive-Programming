#include <bits/stdc++.h>
#define ll long long
#define p 53
#define mod 1000000007
using namespace std;

vector<ll> pre[100007];
int sz[100007];
string s[100007];

ll bigmod( ll x, ll y )
{
    ll res= 1;

    while(y>0)
    {
        if(y&1)
            res= (res*x)%mod;
        x= (x*x)%mod;
        y>>= 1;
    }

    return res%mod;
}

int main()
{
    int n;
    cin>>n;

    for( int i=0;i<n;i++ )
    {
        cin>>s[i];

        int m= s[i].size();
        sz[i]= m;

        ll h= 0;
        pre[i].push_back(0);
        for( int j=0;j<m;j++ )
        {
            ll tmp= (s[i][j]*bigmod( p, j+1 ))%mod;
            h= (h+tmp+mod)%mod;
            pre[i].push_back(h);
        }
    }

    cout<<s[0];

    for( int i=0;i<n-1;i++ )
    {
        int cnt= 0;
        for( int j=1;j<=min( sz[i], sz[i+1] );j++ )
        {
            ll pre1= pre[i+1][j];
            ll post= pre[ i ][ sz[i] ]-pre[i][ sz[i]-j ];
            post= (post+mod)%mod;
            ll niche= bigmod( p, sz[i]-j-1 )%mod;
            ll inv= bigmod( niche, mod-2 )%mod;
            post= (post*inv)%mod;

            cout<<s[i]<<" "<<s[i+1]<<" "<<pre1<<" "<<post<<endl;
            if( pre1==post )
                cnt++;
            else
                break;
        }
        cout<<i<<" "<<cnt<<endl;
//        for( int j=cnt;j<sz[i+1];j++ )
//            cout<<s[i+1][j];
    }
}
