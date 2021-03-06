#include<iostream>
#include<vector>
#include<stdio.h>
#define mx 10007
#define ll long long
using namespace std;

bool ok[mx];
vector<int>primes,v[mx];
int sign[mx];
int hit[mx];

void init()
{
    for( int i=0; i<mx; i++ )
        sign[i]= 1;

    for( ll i=2; i<mx; i++ )
    {
        if(!ok[i])
        {
            hit[i]++;
            for( ll j=i*2; j<mx; j+=i )
            {
                ok[j]= 1;
                hit[j]++;
                ll pp= j;

                pp/= i;

                if(pp%i==0)
                    sign[j]= 0;
            }
        }
    }

    for( ll i=2; i<mx; i++ )
    {
        if(!sign[i])
            continue;
        if(hit[i]&1)
            sign[i]= -1;
    }
}

ll nc4( ll n, ll r )
{
    if(n<r)
        return 0;
    return ( n*(n-1)*(n-2)*(n-3) )/24;
}

ll nc3( ll n, ll r )
{
    if(n<r)
        return 0;
    return ( n*(n-1)*(n-2) )/6;
}

int mp[mx];

int main()
{
    init();
    int n;

    while(scanf("%d", &n)==1)
    {
        int arr[n+5];

        for( int i=0; i<n; i++ )
        {
            cin>>arr[i];

            int k= arr[i];

            for( int p=2; p*p<=k; p++ )
            {
                if( k%p==0 )
                {
                    v[k].push_back(p);
                    mp[p]++;

                    if(p!=k/p)
                        v[k].push_back(k/p), mp[k/p]++;
                }
            }

            v[k].push_back(k);
            mp[k]++;
        }

        ll ans= nc4( n, 4 );
        ll baad= 0;

        for( int i=0; i<n; i++ )
        {
            for( int j=0;j<v[ arr[i] ].size();j++ )
            {
                int x= v[ arr[i] ][j];
                baad-= sign[ x ]*nc3( mp[x]-1, 3 );
            }
            v[ arr[i] ].clear();
        }

        printf("%lld\n", ans-baad/4);

        for( int i=0; i<mx; i++ )
            mp[i]= 0;
    }
}
