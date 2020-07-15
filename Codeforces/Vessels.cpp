#include <bits/stdc++.h>
#define mx 200007
#define ll long long
using namespace std;

ll arr[mx], par[mx], Size[mx];
ll tot[mx];

void init()
{
    for( int i=0; i<mx; i++ )
        par[i]= i, Size[i]= 1;
}

ll Find( int u )
{
    if( par[u]==u )
        return u;
    return par[u]= Find( par[u] );
}

void unite( int u, int v )
{
    int paru= Find( u );
    int parv= Find( v );

    par[paru]= parv;
}

int main()
{
    init();
    ll n;
    scanf("%lld", &n);

    for( int i=1; i<=n; i++ )
        scanf("%lld", &arr[i]);

    ll q;
    scanf("%lld", &q);

    while(q--)
    {
        ll tp;
        scanf("%lld", &tp);

        if( tp==1 )
        {
            ll p,q;
            scanf("%lld %lld", &p, &q);

            ll pp= Find(p);

            if( q+tot[pp]>arr[pp] )
                while( 1 )
                {
                    if( pp==n+1 )
                        break;
                    else if( q+tot[pp]>arr[pp] )
                    {
                        int qq= q-arr[pp]+tot[pp];
                        tot[pp]= arr[pp];
                        unite( pp, Find(pp+1) );
                        pp= Find(pp+1);
                        q= qq;
                    }
                    else
                    {
                        tot[pp]+= q;
                        break;
                    }
                }

            else
                tot[pp]+= q;
        }

        else
        {
            ll p;
            scanf("%lld", &p);
            printf("%lld\n", tot[p]);
        }
    }
}
