#include <bits/stdc++.h>
#define ull unsigned long long
#define INF 1e18
#define pii pair<ull, ull>

using namespace std;

ull parent[1000005];
ull dist[1000005];
bool vis[1000005];

void printPath(ull node)
{
	if(parent[node]==node)
	{
		printf("%llu ", node+1);
		return;
	}
	printPath(parent[node]);
	printf("%llu ", node+1);
}

int main()
{
	ull m,n,p,q,w;
	scanf("%llu %llu", &n,&m);
	vector <pii> adj[n];
	for(ull i=0;i<n;i++)
        dist[i]=INF;
	while(m--)
	{
		scanf("%llu %llu %llu", &p,&q,&w);
		p--;
		q--;
		adj[p].push_back(pii(q,w));
		adj[q].push_back(pii(p,w));
	}
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	dist[0]=0;
	parent[0]=0;
	pq.push(pii(0,0));
	while(!pq.empty())
	{
		ull u=pq.top().second;
		ull c=pq.top().first;
		pq.pop();
		if(dist[u]<c)
			continue;
		for(ull i=0;i<adj[u].size();i++)
		{
			ull node=adj[u][i].first;
			ull cost=adj[u][i].second;
			if(dist[u]+cost<dist[node])
			{
			    vis[node]=1;
				parent[node]=u;
				dist[node]=dist[u]+cost;
				pq.push(pii(dist[node], node));

			}
		}
	}

	if(vis[n-1]==0)
        printf("-1");
    else
	printPath(n-1);

}
