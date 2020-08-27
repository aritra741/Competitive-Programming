#include<bits/stdc++.h>
#define mx 300007
using namespace std;

int par[mx], Size[mx];
int ans[mx];
int vis[mx];

std::vector<int> adj[mx];

int Find( int u )
{
	if (par[u] == u)
		return u;

	return par[u] = Find(par[u]);
}

void unite1( int u, int v )
{
	int paru = Find(par[u]);
	int parv = Find(par[v]);

	if (paru != parv)
	{
		if ( Size[paru] > Size[parv] )
			par[parv] = paru, Size[paru] += Size[parv];
		else
			par[paru] = parv, Size[parv] += Size[paru];
	}
}

void unite2( int u, int v )
{
	int paru = Find(par[u]);
	int parv = Find(par[v]);

	if (paru != parv)
	{
		int nodeu= ans[paru]+1;
		int nodev= ans[parv]+1;

		int totnode= nodeu/2+nodev/2;
		int x = totnode+1;

		x= max( {x,ans[paru],ans[parv]} );

		if ( Size[paru] > Size[parv] )
			par[parv] = paru, Size[paru] += Size[parv], ans[paru] = x;
		else
			par[paru] = parv, Size[parv] += Size[paru], ans[parv] = x;
	}
}

void init(int n)
{
	for ( int i = 1; i <= n; i++ )
		par[i] = i, Size[i] = 1;
}

int node,cnt;

void dfs( int u, int nisi, int x )
{
	if(nisi>cnt)
		cnt= nisi, node= u;
	vis[u]= x;

	for( auto v: adj[u] )
	{
		if(vis[v]==x)
			continue;
		dfs(v,nisi+1,x);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;

	init(n);

	while (m--)
	{
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);

		unite1(u,v);
	}

	for( int i=1;i<=n;i++ )
	{
		if(vis[i])
			continue;

		cnt= 0, node= i;
		dfs(i,0,1);
		cnt= 0;
		dfs(node,0,2);
		ans[Find(i)]= cnt;
	}

	while (q--)
	{
		int tp;
		cin >> tp;

		if (tp == 1)
		{
			int x;
			cin >> x;

			cout << ans[ Find(x) ] << "\n";
		}
		else
		{
			int u, v;
			cin >> u >> v;

			unite2(u, v);
		}
	}
}