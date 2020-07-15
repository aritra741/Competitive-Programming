#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

int arr[100007];
vector<pii> v;

int main()
{
    int n;
    scanf("%d", &n);

    for( int i=0; i<n; i++ )
        scanf("%d", &arr[i]);

    int prev= -1, cnt= 0, l= 0;
    int ans= 2;

    for( int i=0; i<n; i++ )
    {

        if( arr[i]>prev )
            cnt++, prev= arr[i];
        else
        {
            v.push_back( pii( l, l+cnt-1 ) );
            ans= max( ans, cnt+1 );
            l= i;
            prev= arr[i];
            cnt= 0;
        } cout<<l<<" "<<cnt<<endl;
    }

    if(cnt)
        ans= max(ans, cnt+1), v.push_back( pii( l, l+cnt-1 ) );

    if( v.size()==1 )
        return cout<<ans<<endl, 0;

    for( int i=1;i<v.size();i++ )
    {
        if( arr[ v[i].f ]-1>arr[ v[i-1].s ] )
            ans= max( ans, v[i].s-v[i-1].f+1 );
    }

    cout<<ans<<endl;
}
