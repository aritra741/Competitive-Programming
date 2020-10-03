#include <bits/stdc++.h>
#define mx 100007
using namespace std;

std::vector<int> adj[mx];
int dist[mx];
int dur, node;

void dfs( int u, int p, int dd )
{
	dist[u]= dd;
	if( dd>dur )
		dur= dd, node= u;

	for( auto v: adj[u] )
		if( v!=p )
			dfs( v, u, dd+1 );
}

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		int n,a,b,da,db;
		cin>>n>>a>>b>>da>>db;

		for( int i=1;i<n;i++ )
		{
			int p,q;
			cin>>p>>q;

			adj[p].push_back(q);
			adj[q].push_back(p);
		}

		dur= 0;
		dfs( a, a, 0 );
		int dab= dist[b];
		dur= 0;
		dfs( node, node, 0 );

		if( dab<=da or 2*da>=dur or db<=2*da )
			cout<<"Alice\n";
		else
			cout<<"Bob\n";

		for( int i=1;i<=n;i++ )
			adj[i].clear();
	}
}