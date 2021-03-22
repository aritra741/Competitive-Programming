#include <bits/stdc++.h>
#define ll long long
#define mx 1000007
using namespace std;

int phi[mx], lp[mx];
vector<int> primes;
ll ans[mx];

void init()
{
    phi[1]= 1;
    for( ll i=2;i<mx;i++ )
    {
        if( !lp[i] )
        {
            lp[i]= i;
            phi[i]= i-1;
            primes.push_back(i);
        }
        else
        {
            int d= i/lp[i];

            if( d%lp[i] )
                phi[i]= phi[d]*( lp[i]-1 );
            else
                phi[i]= phi[d]*lp[i];
        }

        for( ll j=0;j<primes.size() and primes[j]<=lp[i] and i*primes[j]<mx;j++ )
            lp[ primes[j]*i ]= lp[i];
    }

    for( int i=1;i<mx;i++ )
        for( int j=i;j<mx;j+=i )
            ans[i]+= phi[j/i];
} 

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        int n;
        scanf("%d", &n);

        printf("%lld\n", ans[n]);
    }
}