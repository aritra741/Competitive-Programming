#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define ff first
#define ss second
using namespace std;

pii arr[100007];
ll n, s, k, ans, hoy, ret;

bool cmp( pii a, pii b )
{
    return a.ff+k*a.ss<b.ff+k*b.ss;
}

bool ok()
{
    sort( arr, arr+n, cmp );

    ret= 0;
    for( int i=0;i<k;i++ )
        ret+= arr[i].ff+arr[i].ss*k;

    if( ret<=s )
        return 1;
    return 0;
}

int main()
{
    cin>>n>>s;

    for( int i=0;i<n;i++ )
        cin>> arr[i].ff, arr[i].ss= i+1;

    ans= 1e18;
    int l= 0, r= n;

    while( r-l>5 )
    {
        int mid= (r+l)/2;
        k= mid;

        if( ok() )
        {
            if( hoy==k )
                ans= min( ans, ret );
            else
                hoy= k, ans= ret;

            l= mid;
        }
        else
            r= mid;
    }

    while(l<=r)
    {
        k= l;
        if( ok() )
        {
            if( hoy==k )
                ans= min( ans, ret );
            else if( l>hoy )
                hoy= k, ans= ret;
        }

        l++;
    }

    if( !hoy )
        ans= 0;

    cout<<hoy<<" "<<ans<<endl;
}
