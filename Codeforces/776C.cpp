#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll mx= 1e14;
map<ll,ll>mp;
ll arr[100007], sum[1000007];
ll P[70];
int lim;

void init( ll x )
{
    P[0]= 1;
    lim= 0;

    if(x==-1)
    {
        P[1]= -1;
        lim= 1;
        return;
    }
    if(x==1)
        return;

    for( int i=1;i<=60;i++ )
    {
        if(llabs(P[i-1])>=mx)
            break;
        P[i]= P[i-1]*x;
        lim= i;
    }
}

int main()
{
    int n,k;
    cin>>n>>k;

    init(k);

    for( int i=1;i<=n;i++ )
        cin>>arr[i], sum[i]= sum[i-1]+arr[i];

    ll ans= 0;
    for( int i=n;i>=1;i-- )
    {
        mp[ sum[i] ]++;
        for( int j=0;j<=lim;j++ )
            ans+= mp[ P[j]+sum[i-1] ];
    }

    cout<< ans <<endl;
}


