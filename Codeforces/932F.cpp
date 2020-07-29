#include<bits/stdc++.h>
#define ll long long
#define mx 100007
using namespace std;

ll a[mx], b[mx];
vector<int>adj[mx];
ll dp[mx];

// Keeps upper hull for maximums.
// add lines with -m and -b and return -ans to
// make this code working for minimums.

typedef long double ld;
const ld inf = 1e18;

struct chtDynamic {
	struct line {
		ll m, b; ld x;
		ll val; bool isQuery;
		line(ll _m = 0, ll _b = 0) :
			m(_m), b(_b), val(0), x(-inf), isQuery(false) {}

		ll eval(ll x) const { return m * x + b;	}
		bool parallel(const line &l) const { return m == l.m; }
		ld intersect(const line &l) const {
			return parallel(l) ? inf : 1.0 * (l.b - b) / (m - l.m);
		}
		bool operator < (const line &l) const {
			if(l.isQuery) return x < l.val;
			else return m < l.m;
		}
	};

	set<line> hull;
	typedef set<line> :: iterator iter;

	bool cPrev(iter it) { return it != hull.begin(); }
	bool cNext(iter it) { return it != hull.end() && next(it) != hull.end(); }

	bool bad(const line &l1, const line &l2, const line &l3) {
		return l1.intersect(l3) <= l1.intersect(l2);
	}
	bool bad(iter it) {
		return cPrev(it) && cNext(it) && bad(*prev(it), *it, *next(it));
	}

	iter update(iter it) {
		if(!cPrev(it)) return it;
		ld x = it -> intersect(*prev(it));
		line tmp(*it); tmp.x = x;
		it = hull.erase(it);
		return hull.insert(it, tmp);
	}

	void addLine(ll m, ll b) {
		line l(m, b);
		iter it = hull.lower_bound(l);
		if(it != hull.end() && l.parallel(*it)) {
			if(it -> b < b) it = hull.erase(it);
			else return;
		}

		it = hull.insert(it, l);
		if(bad(it)) return (void) hull.erase(it);

		while(cPrev(it) && bad(prev(it))) hull.erase(prev(it));
		while(cNext(it) && bad(next(it))) hull.erase(next(it));

		it = update(it);
		if(cPrev(it)) update(prev(it));
		if(cNext(it)) update(next(it));
	}

	ll query(ll x) const {
		if(hull.empty()) return -inf;
		line q; q.val = x, q.isQuery = 1;
		iter it = --hull.lower_bound(q);
		return it -> eval(x);
	}
}hd[mx];

void dfs( int u, int p )
{
//    cout<<u<<" "<<p<<endl;

    for( auto v: adj[u] )
    {
        if(v==p)
            continue;

        dfs( v,u );

        if( hd[u].hull.size()<hd[v].hull.size() )
            hd[u].hull.swap(hd[v].hull);

        for( auto x: hd[v].hull )
            hd[u].addLine(x.m, x.b);

        hd[v].hull.clear();
    }

    if( adj[u].size()>1 or u==1 )
        dp[u]= -hd[u].query(a[u]);

    hd[u].addLine( -b[u], -dp[u] );
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    for( int i=1; i<=n; i++ )
        cin>>a[i];
    for( int i=1; i<=n; i++ )
        cin>>b[i];

    for( int i=1; i<n; i++ )
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,1);

    for( int i=1;i<=n;i++ )
        cout<<dp[i]<<" ";
}
