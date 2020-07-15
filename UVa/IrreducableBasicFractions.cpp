#include <bits/stdc++.h>
#define ll long long
#define mx 100000007
#define eps 1e-9
using namespace std;

int phi[mx], lp[mx];
vector<int>prime;

void Sieve_phi()
{
    phi[1]= 1;

    for( ll i=2; i<mx; i++ )
    {
        if( !lp[i] )
        {
            lp[i]= i;
            phi[i]= i-1;
            prime.push_back((int)i);
        }

        else
        {
            int d= i/lp[i];

            if( d%lp[i] )
                phi[i]= phi[d]*( lp[i]-1 );
            else
                phi[i]= phi[d]*lp[i];
        }

        for( int j=0; j<prime.size() and prime[j]<=lp[i] and i*prime[j]<mx; j++ )
            lp[ i*prime[j] ]= prime[j];
    }
}

int Phi( int n )
{
    int ans= n;
    for( int i=0; i<prime.size() and (ll)prime[i]*prime[i]<=n; i++ )
    {
        if( n%prime[i]==0 )
        {
            while( n%prime[i]==0 )
                n/= prime[i];

            ans/= prime[i];
            ans*= (prime[i]-1);
        }
    }

    if( n>1 )
        ans/= n, ans*= n-1;

    return ans;
}

int main()
{
    Sieve_phi();

    int n;

    while(scanf("%d", &n)==1 and n)
    {
        if( n<=100000000 )
            printf("%d\n", phi[n]);
        else
            printf("%d\n", Phi(n));
    }
}
