#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define piii pair<pii,ll>
#define ff first
#define ss second
#define mx 100007
#define sf(x) scanf("%lld", &x)
using namespace std;

std::vector<pii> adj[mx];
std::vector<piii> edges;
ll dist[mx];
bool ok[mx];

int main()
{
	ll n, m, k;
	sf(n);
	sf(m);
	sf(k);

	for ( int i = 0; i < m; i++ )
	{
		ll u, v;
		ll w;
		sf(u);
		sf(v);
		sf(w);

		adj[u].push_back( pii(v, w) );
		adj[v].push_back( pii(u, w) );
	}

	for ( int i = 0; i < k; i++ )
	{
		ll s, y;
		sf(s);
		sf(y);

		edges.push_back(piii(pii(s, y), i));
	}

	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push(pii(0, 1));

	memset( dist, 0x3f, sizeof(dist) );
	dist[1] = 0;

	while (!pq.empty())
	{
		pii tp = pq.top();
		pq.pop();

		int u = tp.ss;
		ll w = tp.ff;

		if ( w > dist[u] )
			continue;
		if ( w == dist[u] and u != 1 )
			continue;

		for ( auto x : adj[u] )
		{
			int v = x.ff;
			ll c = x.ss;

			if ( dist[u] + c < dist[v] )
			{
				dist[v] = dist[u] + c;
				pq.push(pii(dist[v], v));
			}
		}
	}

	pq.push(pii(0,1));

	while (!pq.empty())
	{
		pii tp = pq.top();
		pq.pop();

		int u = tp.ss;
		ll w = tp.ff;

		if ( w > dist[u] )
			continue;
		if ( w == dist[u] and u != 1 )
			continue;

		for ( auto x : adj[u] )
		{
			int v = x.ff;
			ll c = x.ss;

			if ( dist[u] + c < dist[v] )
			{
				dist[v] = dist[u] + c;
				pq.push(pii(dist[v], v));
			}
		}

		if (u == 1)
			for ( auto x : edges )
			{
				int id = x.ss;
				int v = x.ff.ff;
				ll c = x.ff.ss;

				if ( c < dist[v] )
				{
					ok[id] = 1;
					dist[v] = c;
				}
			}
	}

	int ans = 0;

	for ( int i = 0; i < k; i++ )
		if ( !ok[i] )
			ans++;

	printf("%d\n", ans);
}