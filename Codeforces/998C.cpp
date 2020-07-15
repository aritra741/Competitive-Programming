#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;

    char c= '2';
    ll m= 0;

    for( int i=0;i<n;i++ )
    {
        if( s[i]!=c and s[i]=='0' )
            m++;
        c= s[i];
    }

    ll ans= 1e18;

    for( ll i=1;i<=m;i++ )
        ans= min( ans, x*(i-1)+y*( m-i+1 ) );

    ans= min( ans, m*y );
    if(m)
        ans= min( ans, (m-1)*x+y );

    cout<< ans <<endl;
}

