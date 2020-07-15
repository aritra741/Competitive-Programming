#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

pii arr[100007];

int main()
{
    int n,d;
    cin>>n>>d;

    for( int i=0;i<n;i++ )
        cin>>arr[i].f>>arr[i].s;

    sort( arr, arr+n );

    int p= 0, q= 1;
    ll ans= 0, now= arr[0].s;

    while(p<n and q<n)
    {
        if( arr[q].f-arr[p].f<d )
            now+= arr[q].s, ans= max( ans, now ), q++;
        else
            ans= max(ans, now), now-= arr[p].s, p++;
    }

    ans= max( ans, now );

    cout<< ans <<endl;
}
