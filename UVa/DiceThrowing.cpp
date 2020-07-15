#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[25][3605];
bool vis[25][3605];
ll n, mn, cap;
ll tot=0;

ll power(ll b, ll p)
{
    if(!p)return 1;

    ll a=power(b,p>>1);
    ll c=a*a;

    if(p&1)return c*b;

    return c;
}

ll rec( int curr, int cnt )
{
    if(cnt==n)
    {
        if(curr>=mn)
            return 1;
        return 0;

    }
    if(vis[cnt][curr])
        return dp[cnt][curr];

    ll p1=0;

    for(int j=1; j<=6; j++)
    {
        p1+= rec( curr+j, cnt+1 );
    }

    vis[cnt][curr]=1;

    return dp[cnt][curr]= p1;
}

int main()
{
    while(1)
    {
        cin>>n>>mn;

        if(n+mn==0)
            break;

        cap=n*6;

        ll numer= rec(0,0);
        ll denom= power(6, n);

        ll g= __gcd(numer, denom);

        ll newNumer= numer/g;
        ll newDenom= denom/g;

        if(!newNumer)
            cout<<"0"<<endl;
        else if(newNumer==newDenom)
            cout<<"1"<<endl;
        else
            cout<<newNumer<<"/"<<(denom/g)<<endl;

        memset(vis, 0, sizeof(vis));
    }
}
