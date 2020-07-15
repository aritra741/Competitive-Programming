#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define pii pair<int,int>
#define piii pair<int,pii>
using namespace std;

ll n,m,k;
ll arr[100007];
vector<pii>v;
map<int,int>mp;
priority_queue<piii>pq;

int main()
{
    cin>>n>>m>>k;

    for( int i=0;i<n;i++ )
        cin>> arr[i];

    for( int i=1;i<n;i++ )
        pq.push( piii(arr[i-1]-arr[i], pii( i-1, i ) ) );

    for( int i=0;i<n-k;i++ )
        v.push_back(pii(pq.top().ss.ff,pq.top().ss.ss)),
        mp[pq.top().ss.ss]++, mp[pq.top().ss.ff]++, pq.pop();

    if( v.size() )
        int fir= arr[0], last= arr[0];

    ll ans= 0;
    int x= v.size();

    for( int i=0;i<x;i++ )
        ans+= arr[v[i].ss]-arr[v[i].ff]-1; /// vacant places

    ll necessary= n;    /// broken places

    cout<<ans+n<<endl;
}
