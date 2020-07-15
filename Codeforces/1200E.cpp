#include <bits/stdc++.h>
#define ll long long
#define p 257
#define p2 311
#define mod 1000000007
#define mod2 1000002727
using namespace std;

vector<ll> pre[100007][2], post[100007][2];
int sz[100007];
string s[100007];
ll Pow[1000007], Pow2[1000007];

void precal()
{
    Pow[0]= 1;
    for( ll i=1; i<1000007; i++ )
        Pow[i]= (Pow[i-1]*p)%mod;
    Pow2[0]= 1;
    for( ll i=1; i<1000007; i++ )
        Pow2[i]= (Pow2[i-1]*p2)%mod2;

}

int main()
{
    precal();

    int n;
    cin>>n;

    for( int i=0; i<n; i++ )
    {
        cin>>s[i];

        int m= s[i].size();
        sz[i]= m;

        ll h= 0, h2= 0;
        pre[i][0].push_back(0);
        pre[i][1].push_back(0);
        for( int j=0; j<m; j++ )
        {
            ll tmp= (s[i][j]*Pow[j+1])%mod;
            ll tmp2= (s[i][j]*Pow2[j+1])%mod2;
            h= (h+tmp+mod)%mod;
            h2= (h2+tmp2+mod2)%mod2;
            pre[i][0].push_back(h);
            pre[i][1].push_back(h2);
        }
        post[i][0].push_back(0);
        post[i][1].push_back(0);
        h= 0, h2= 0;

        for( int j=m-1; j>=0; j-- )
        {
            ll tmp= (s[i][j]*p)%mod;
            ll tmp2= (s[i][j]*p2)%mod2;
            ll tt= (h*p)%mod;
            ll tt2= (h2*p2)%mod2;
            h= (tmp+tt)%mod;
            h= (h+mod)%mod;
            h2= (tmp2+tt2)%mod2;
            h2= (h2+mod2)%mod2;

            post[i][0].push_back(h);
            post[i][1].push_back(h2);
        }

    }

    cout<<s[0];

    for( int i=0; i<n-1; i++ )
    {
        int cnt= 0;
        for( int j=min( sz[i], sz[i+1] ); j>=1; j-- )
        {
            ll pre1= pre[i+1][0][j];
            ll post1= post[i][0][j];
            ll pre2= pre[i+1][1][j];
            ll post2= post[i][1][j];

            if( pre1==post1 and pre2==post2 )
            {
                cnt= j;
                break;
            }
        }

        for( int j=cnt; j<sz[i+1]; j++ )
            cout<<s[i+1][j];
    }
}

/*
3
bbA0A 0Aa Aaa
*/
