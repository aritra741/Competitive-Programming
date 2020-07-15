#include<bits/stdc++.h>
#define ll long long
#define mx 1000007
using namespace std;

bool arr[mx];
int sign[mx];
int hit[mx];

void init()
{
    for( int i=0;i<mx;i++ )
        sign[i]= 1;

    for( ll i=2; i<mx; i++ )
    {
        if(!arr[i])
        {
            hit[i]++;
            for( ll j=i*2; j<mx; j+=i )
            {
                arr[j]= 1;
                hit[j]++;
                ll pp= j;

                pp/= i;

                if(pp%i==0)
                    sign[j]= 0;
            }
        }
    }

    for( ll i=2;i<mx;i++ )
    {
        if(!sign[i])
            continue;
        if(hit[i]&1)
            sign[i]= -1;
    }
}

int main()
{
    init();

    int tc;
    scanf("%d", &tc);

    for( int t=1; t<=tc; t++ )
    {
        ll n,m;
        scanf("%lld %lld", &n, &m);

        ll ans= n*m;

        for( int i=2;i<=min(n,m);i++ )
            ans+= sign[i]*(n/i)*(m/i);

        if(n and m)
            ans+= 2;
        else if(n or m)
            ans= 1;

        printf("Case %d: %lld\n", t, ans);    /// +2 because of x and y axis shot
    }
}
