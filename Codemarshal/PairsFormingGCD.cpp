#include <bits/stdc++.h>
#define ll long long
#define mx 10000007
using namespace std;

int phi[mx], lowprime[mx];
ll sum[mx];
vector<ll> pr;

void genphi()
{
    phi[1]= 1;
    for( ll i=2;i<mx;i++ )
    {
        if( !lowprime[i] )
        {
            pr.push_back( i );
            phi[i]= i-1;
            lowprime[i]= i;
        }

        else
        {
            int d= i/lowprime[i];

            if( d%lowprime[i] )
                phi[i]= phi[d]*( lowprime[i]-1 );
            else
                phi[i]= phi[d]*lowprime[i];
        }

        for( ll j=0;j<(int)pr.size() and pr[j]<=lowprime[i] and i*pr[j]<mx;j++ )
            lowprime[pr[j]*i]= pr[j];
    }

    for( int i=1;i<mx;i++ )
        sum[i]= phi[i]+sum[i-1];
}

int main()
{
    genphi();

    int tc;
    scanf("%d", &tc);

    for( int t=1;t<=tc;t++ )
    {
        ll n,p;
        scanf("%lld %lld", &n, &p);

        ll l= 1, r= n, ans= -1;

        while(r-l>5)
        {
            ll g= (l+r)/2;
            ll tot= n/g;

            if(sum[tot]>=p)
                ans= g, l= g;
            else
                r= g;
        }

        while(l<=r)
        {
            ll now= n/l;
            if( sum[now]>=p and l>ans )
                ans= l;
            l++;
        }

        printf("Case %d: %lld\n", t, ans);
    }
}
