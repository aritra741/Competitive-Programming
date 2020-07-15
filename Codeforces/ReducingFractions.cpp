#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> prime, a, b;

bool arr[1000007];

void sieve()
{
    arr[0]=arr[1]= 1;

    for( ll i=2; i<1000007; i++ )
    {
        if(!arr[i])
        {
            prime.push_back( i );
            for( ll j=i*i; j<1000007; j+=i )
                arr[j]= 1;
        }
    }
}

int main()
{
    sieve();

    ll n,m,p;
    cin>>n>>m;

    ll numer= 1, denom= 1;

    for( int i=0; i<n; i++ )
        cin>>p, numer*= p;
    for( int i=0; i<m; i++ )
        cin>>p, denom*= p;

    ll num= numer/__gcd( numer, denom );
    ll den= denom/__gcd( numer, denom );

    if( num>10000000 )
    {
        for( int i=0; i<prime.size() and prime[i]*prime[i]<=num; i++ )
            while( num%prime[i]==0 )
            {
                num/= prime[i], a.push_back(prime[i]);
                if( a.size()>100000 )
                    a[ 100000 ]= a[99999]*a[ 100000 ];
            }
        if( num>1 )
            a.push_back( num );
    }
    if( !a.size() )
        a.push_back( num );

    if( den>10000000 )
    {
        for( int i=0; i<prime.size() and prime[i]*prime[i]<=den; i++ )
            while( den%prime[i]==0 )
            {
                den/= prime[i], b.push_back(prime[i]);

                if( b.size()>100000 )
                    b[ 100000 ]= b[99999]*b[ 100000 ];
            }
        if( den>1 )
            b.push_back( den );
    }
    if( !b.size() )
        b.push_back( den );

    cout<< a.size() <<" "<< b.size() <<endl;
    for( int i=0; i<a.size(); i++ )
        cout<< a[i] <<" ";

    cout<<endl;

    for( int i=0; i<b.size(); i++ )
        cout<< b[i] <<" ";
}
