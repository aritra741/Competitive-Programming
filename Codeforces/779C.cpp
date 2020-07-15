#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

bool done[200007];
int ekhon[200007], pore[200007];
pii diff[200007];

int main()
{
    int n,k;
    cin>>n>>k;

    for( int i=0; i<n; i++ )
        cin>>ekhon[i];
    for( int i=0; i<n; i++ )
    {
        cin>>pore[i];

        if(pore[i]<ekhon[i])
            diff[i].f= -pore[i]+ekhon[i];
        else
            diff[i].f= 2e9;
        diff[i].s= i;
    }

    sort( diff, diff+n );

    ll ans= 0;
    for( int i=0; i<n; i++ )
        if( pore[i]>=ekhon[i] )
            ans+= ekhon[i], k--, done[i]= 1;

    int i= 0;

    while(i<n and k>0)
        ans+= ekhon[diff[i].s], done[diff[i].s]= 1, i++, k--;

    for( int i=0;i<n;i++ )
        if(!done[i])
            ans+= pore[i];

    cout<< ans <<endl;
}
