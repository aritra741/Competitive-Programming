#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define ff first
#define ss second
using namespace std;

///works for negative edges too
///if gets TLE for positive edges use dijkstra instead of spfa
///Complexity: O(min(E^2 *V log V, E logV * flow))
struct edge {
	int u, v;
	long long cap, cost;
	edge(int _u, int _v, long long _cap, long long _cost) {
		u = _u; v = _v; cap = _cap; cost = _cost;
	}
};
///Works for both directed and undirected and with negative cost too
///for undirected just make the directed flag false
struct PrimalDual {
	int n, s, t;
	long long flow, cost;
	vector<vector<int> > g;
	vector<edge> e;
	vector<long long> dist, potential;
	vector<int> parent;
	bool negativeCost;
	PrimalDual(int _n) {
/// 0-based indexing
		n = _n;
		g.assign(n, vector<int> ());
		negativeCost = false;
	}
	void addedge(int u, int v, long long cap, long long cost, bool
	             directed = true) {
		if (cost < 0) negativeCost = true;
		g[u].push_back(e.size());
		e.push_back(edge(u, v, cap, cost));
		g[v].push_back(e.size());
		e.push_back(edge(v, u, 0, -cost));
		if (!directed) addedge(v, u, cap, cost, true);
	}
///returns {maxflow,mincost}
	pair<long long, long long> mincost_maxflow(int _s, int _t) {
		s = _s; t = _t;
		flow = 0, cost = 0;
		potential.assign(n, 0);
		if (negativeCost) {
/// run Bellman-Ford to find starting potential
			dist.assign(n, 1LL << 62);
			for (int i = 0, relax = false; i < n && relax; i++, relax = false) {
				for (int u = 0; u < n; u++) {
					for (int k = 0; k < g[u].size(); k++) {
						int eIdx = g[u][i];
						int v = e[eIdx].v, cap = e[eIdx].cap, w = e[eIdx].cost;
						if (dist[v] > dist[u] + w && cap > 0) {
							dist[v] = dist[u] + w;
							relax = true;
						}
					}
				}
			}
			for (int i = 0; i < n; i++) {
				if (dist[i] < (1LL << 62)) {
					potential[i] = dist[i];
				}
			}
		}
		while (dijkstra()) {
			flow += sendFlow(t, 1LL << 62);
		}
		return make_pair(flow, cost);
	}
	bool dijkstra() {
		parent.assign(n, -1);
		dist.assign(n, 1LL << 62);
		priority_queue<pll, vector<pll>, greater<pll> > pq;
		dist[s] = 0;
		pq.push(pll(0, s));
		while (!pq.empty()) {
			int u = pq.top().second;
			long long d = pq.top().first;
			pq.pop();
			if (d != dist[u]) continue;
			for (int i = 0; i < g[u].size(); i++) {
				int eIdx = g[u][i];
				int v = e[eIdx].v, cap = e[eIdx].cap;
				int w = e[eIdx].cost + potential[u] - potential[v];
				if (dist[u] + w < dist[v] && cap > 0) {
					dist[v] = dist[u] + w;
					parent[v] = eIdx;
					pq.push(pll(dist[v], v));
				}
			}
		}
/// update potential
		for (int i = 0; i < n; i++) {
			if (dist[i] < (1LL << 62))
				potential[i] += dist[i];
		}
		return dist[t] != (1LL << 62);
	}
	long long sendFlow(int v, long long curFlow) {
		if (parent[v] == -1) return curFlow;
		int eIdx = parent[v];
		int u = e[eIdx].u, w = e[eIdx].cost;
		long long f = sendFlow(u, min(curFlow, e[eIdx].cap));
		cost += f * w;
		e[eIdx].cap -= f;
		e[eIdx ^ 1].cap += f;
		return f;
	}
};

char t[107], s[107][107];
int cnt_in_t[30], cnt_in_s[107][30];

int main()
{
	scanf("%s", t);
	int szz= strlen(t);

	for( int i=0;i<szz;i++ )
		cnt_in_t[ t[i]-'a' ]++;

	int n;
	scanf("%d", &n);

	PrimalDual flow( n+35 );
	int src= n+26+2, sink= n+26+3;

	for ( int i = 1; i <= n; i++ )
	{
		int tmp;
		scanf("%s %d", s[i], &tmp);

		flow.addedge( src, i, tmp, 0 );

		int sz= strlen(s[i]);

		for( int j=0;j<sz;j++ )
			cnt_in_s[i][ s[i][j]-'a' ]++;

		for( int j=0;j<26;j++ )
			flow.addedge( i, n+j+1, cnt_in_s[i][j], i );
	}

	for( int j=0;j<26;j++ )
		flow.addedge( j+n+1, sink, cnt_in_t[j], 0 );

	pll ans= flow.mincost_maxflow(src,sink);
	
	if( ans.ff!=szz )
		ans.ss= -1;

	printf("%lld\n", ans.ss);
}
