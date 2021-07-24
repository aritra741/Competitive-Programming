#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define mod 1000000007
#define yes() cout<<"Yes\n"
#define no() cout<<"No\n"
#define mod 1000000007
#define ll long long
#define mx 200007
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define ff first
#define ss second
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int par[mx], sz[mx];

int Find( int u )
{
	if(u==par[u])
		return u;
	return par[u]= Find(par[u]);
}

void unite( int u, int v )
{
	int paru= Find(u);
	int parv= Find(v);
	
	if(paru!=parv)
	{
		if( sz[paru]>sz[parv] )
			sz[paru]+= sz[parv], par[parv]= paru;
		else
			sz[parv]+= sz[paru], par[paru]= parv;		
	}
}

void init(int n)
{
	for( int i=0;i<=n;i++ )
		par[i]= i, sz[i]= 1;
}

int main()
{
	fast;

	ll n,k,x;
	cin>>n>>k>>x;

	init(n);

	pii arr[n+5], brr[n+5];

	for( int i=0;i<n;i++ )
		cin>>arr[i].ff, arr[i].ss= i, brr[i]= arr[i];

	sort( arr, arr+n );

	priority_queue<piii,vector<piii>,greater<piii>>pq;

	for( int i=1;i<n;i++ )
		pq.push( piii(arr[i].ff-arr[i-1].ff,pii(arr[i].ss,arr[i-1].ss)) );		

	while(!pq.empty())
	{
		piii u= pq.top();
		pq.pop();

		if( u.ff<=x )
			unite( u.ss.ff, u.ss.ss );
		else
		{
			ll lagbe= (u.ff-x+x-1)/x;

			if(lagbe<=k)
			{
				k-= lagbe;
				unite( u.ss.ff, u.ss.ss );
			}
		}
	}

	ll ans= 0;

	for( int i=0;i<n;i++ )
		if( Find(i)==i )
			ans++;

	cout<<ans;
}

