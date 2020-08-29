#include <bits/stdc++.h>
#define pll pair<long long, long long>
using namespace std;
vector< pll > arr[30005];
bool vis[30005];
int nxt;


long long MAX= -100000;

void dfs(long long node, long long weight)
{
    if(weight > MAX)
        {
            MAX=weight;
            nxt=node;
        }
    for(int i=0;i<arr[node].size();i++)
    {
        if(vis[arr[node][i].first]==0)
        {
            vis[ arr[node][i].first ]=1;
            dfs( arr[node][i].first, arr[node][i].second+weight  );
        }
    }
}

int main()
{
	int tc;
	cin>>tc;
	for(int t=1;t<=tc;t++)
	{
		long long nodes,p,q,w;
		scanf("%lld", &nodes);
		for(int i=1;i<nodes;i++)
        {
            scanf("%lld %lld %lld", &p, &q, &w);
            arr[p].push_back( pll(q,w) );
            arr[q].push_back( pll(p,w) );
        }
        MAX=-100000;
        memset( vis, 0, sizeof(vis) );
        vis[0]=1;
        dfs(0, 0);
        memset( vis, 0, sizeof(vis) );

        MAX=-100000;
        vis[nxt]=1;
        dfs( nxt, 0 );
        printf("Case %d: %lld\n", t, MAX);
        for(int i=0;i<nodes;i++)
            arr[i].clear();
	}
}
