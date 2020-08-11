#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll suff[100007];
int ans[100007];

int main()
{
    int n,m;
    cin>>n>>m;

    ll l[m+5];
    ll sum= 0;

    for( int i=0;i<m;i++ )
        cin>>l[i], sum+= l[i];

    if( sum<n )
        return cout<<"-1\n", 0;

    for( int i=m-1;i>=0;i-- )
        suff[i]= suff[i+1]+l[i];

    for( int i=1;i<=m;i++ )
    {
        int pos= max( i*1LL, n-suff[i-1]+1 );

        if( pos+l[i-1]-1>n )
            return cout<<"-1\n", 0;

        ans[i]= pos;
    }

    for( int i=1;i<=m;i++ )
        cout<< ans[i] <<" ";
}
