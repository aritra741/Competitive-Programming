#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define mod 1000000007
#define yes() cout<<"Yes\n"
#define no() cout<<"No\n"
#define mod 1000000007
#define ll long long
#define mx 300007
#define pii pair<int,int>
#define piii pair<int,pii>
#define ff first
#define ss second
using namespace std;

std::vector<int> adj[mx], wt[mx];
int dist[mx];

int main()
{
	fast;

	int tc;
	cin>>tc;

	while(tc--)
	{
		int n,k;
		cin>>n>>k;

		int arr[k+5];

		for( int i=0;i<k;i++ )
			cin>>arr[i];

		for( int i=1;i<=n;i++ )
			dist[i]= 2e9;

		for( int i=0;i<k;i++ )
		{
			int x;
			cin>>x;

			adj[0].push_back(arr[i]);
			wt[0].push_back(x);
		}

		for( int i=1;i<=n;i++ )
		{
			if( i>1 )
				adj[i].push_back(i-1),
				wt[i].push_back(1);
			if( i<n )
				adj[i].push_back(i+1),
				wt[i].push_back(1);
		}
		
		priority_queue<pii,vector<pii>,greater<pii>>pq;
		pq.push(pii(0,0));

		while(!pq.empty())
		{
			pii u= pq.top();
			pq.pop();

			if( dist[u.ss]<u.ff )
				continue;

			for( int i=0;i<adj[u.ss].size();i++ )
			{
				int v= adj[u.ss][i];
				int c= wt[u.ss][i];

				if( c+dist[u.ss]<dist[v] )
				{
					dist[v]= c+dist[u.ss];
					pq.push( pii(dist[v],v) );
				}
			}
		}

		for( int i=1;i<=n;i++ )
			cout<<dist[i]<<" ", adj[i].clear(), wt[i].clear();
		cout<<"\n";

		adj[0].clear();
		wt[0].clear();
	}	
}