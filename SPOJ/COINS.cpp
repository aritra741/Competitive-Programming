#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<ll,ll> dp;
ll n;

ll rec( ll m )
{
    if( !m )
        return 0LL;

    if( dp[m] )
        return dp[m];

    ll q1= m;
    ll q2= rec( m/2 );
    ll q3= rec( m/3 );
    ll q4= rec( m/4 );

    return dp[m]= max( q1, q2+q3+q4 );
}

int main()
{
    while( cin>>n )
    {
        cout<< rec( n ) <<endl;
    }
}
