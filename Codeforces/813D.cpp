#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ff first
#define ss second
#define N 20507
using namespace std;
 
struct MCMF {
    using T = ll; static const T inf = 1e9 + 7;
    int n, m, s, t; bool vis[N];
    ll par[N], pos[N]; T pot[N], dis[N], left[N];
    priority_queue <pair <T, int>> q;
    struct edge {
        int to, rev; T cap, cost, flow; int id;
    };
    vector<edge>ed[N];
    MCMF() {}
    MCMF(int _n) {
        n = _n + 2;
        for (int i = 1; i <= n; i++) ed[i].clear();
    }
    void add_edge(int u, int v, T cap, T cost, int id = -1) {
        edge a = {v, (int)ed[v].size(), cap, cost, 0, id};
        edge b = {u, (int)ed[u].size(), 0, -cost, 0, -1};
        ed[u].push_back(a); ed[v].push_back(b);
    }
    T BellmanFord(int u) {
        if (vis[u]) return pot[u];
        if (u == s) {
            pot[s] = 0;
            return 0;
        }
        vis[u] = true; pot[u] = inf;
        for (edge e : ed[u]) {
            edge r = ed[e.to][e.rev];
            if (r.flow < r.cap) pot[u] = min(pot[u], BellmanFord(e.to) + r.cost);
        }
        return pot[u];
    }
    bool dijkstra() {
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; i++) dis[i] = left[i] = inf;
        dis[s] = 0; q.push({0, s}); int u, v;
        while (!q.empty()) {
            u = q.top().second; q.pop();
            if (vis[u]) continue;
            vis[u] = true; int ptr = 0;
            for(edge e : ed[u]) {
                v = e.to; T cost = e.cost + pot[u] - pot[v];
                if (e.flow < e.cap && dis[u] + cost < dis[v]) {
                    dis[v] = dis[u] + cost;
                    par[v] = u; pos[v] = ptr;
                    left[v] = min(left[u], e.cap - e.flow);
                    q.push(make_pair(-dis[v], v));
                }
                ++ptr;
            }
        }
        for (int i = 1; i <= n; i++) dis[i] += (pot[i] - pot[s]);
        return vis[t];
    }
    pair<T, T> solve(int _s, int _t, T goal = inf) {
        s = _s; t = _t;
        memset(pot, 0, sizeof pot);
        memset(vis, 0, sizeof vis);
        BellmanFord(t);
        int u, v; T ans = 0, cost = 0, f;
        while (ans < goal && dijkstra()) {
            u = t; f = left[t];
            while (u != s) {
                v = par[u];
                ed[v][pos[u]].flow += left[t];
                ed[u][ed[v][pos[u]].rev].flow -= left[t];
                u = v;
            }
            T need = goal - ans; f = min(f, need);
            ans += f; cost += f * dis[t];
            memcpy(pot, dis, sizeof dis);
        }
        return make_pair(ans, cost);
    }
};
 
int arr[5007];
int next_same[100007], next_same_mod[10];

int main()
{
	int n;
	scanf("%d", &n);
 
	MCMF flow(4*n+7);
	int src= 4*n+2, sink= 4*n+3;
 
	for( int i=1;i<=n;i++ )
		scanf("%d", &arr[i]);
 	
	for( int i=1;i<=100000;i++ )
		next_same[i]= sink;
	for( int i=0;i<7;i++ )
		next_same_mod[i]= sink;

	for( int i=1;i<=n;i++ )
	{
		int to= next_same_mod[arr[i]%7];
		flow.add_edge( i+2*n, to, flow.inf, 0 ); // skip the current node and go to a similar one
		flow.add_edge( i+2*n, i, 1, 0 ); // take the current node
		flow.add_edge( i+n, to, 1, 0 ); 	// can take the next node with same mod
		next_same_mod[arr[i]%7]= i+2*n;

		to= next_same[ arr[i] ];
		flow.add_edge( i+3*n, to, flow.inf, 0 ); // // skip the current node and go to a similar one
		flow.add_edge( i+3*n, i, 1, 0 ); // take the current node
		flow.add_edge( i+n, next_same[ arr[i]+1 ], 1, 0 ); // can take the next node with +1
		flow.add_edge( i+n, next_same[ arr[i]-1 ], 1, 0 ); // can take the next node with -1
		next_same[arr[i]]= i+3*n;
	}

	for( int i=1;i<=n;i++ )
		flow.add_edge( src, i, 1, 0 ),
		flow.add_edge( i, i+n, 1, -1 ),
		flow.add_edge( i+n, sink, 1, 0 );
 
	ll ans= flow.solve(src,sink,2).ss;
 
	printf("%lld\n", abs(ans));
}