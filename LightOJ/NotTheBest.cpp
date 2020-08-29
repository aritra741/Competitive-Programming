#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main()
{
	int tc;
	scanf("%d", &tc);
	for(int i=1;i<=tc;i++)
	{
		int p,q,n,r,c;
		int cnt=0;
		scanf("%d %d", &n,&r);
		vector <pii> graph[n+1];
		while(r--)
		{
			scanf("%d %d %d", &p,&q,&c);
			graph[p].push_back(pii(q,c));
			graph[q].push_back(pii(p,c));
		}
		priority_queue <pii> pq;
		int d1[n+1],d2[n+1];
		memset(d1, 0x3f3f3f3f, sizeof(d1));
		memset(d2, 0x3f3f3f3f, sizeof(d2));
		d1[1]=0;
		pq.push(pii(0, 1));
		while(!pq.empty())
		{
			int u=pq.top().second;
			int w=pq.top().first;
			pq.pop();
			if(d1[u]<w && d2[u]<w)
				continue;
			for(int it=0;it<graph[u].size();it++)
			{
				int weight=graph[u][it].second;
				int node=graph[u][it].first;
				if(w+weight<d1[node])
				{
					d2[node]=d1[node];
					d1[node]=w+weight;
					pq.push(pii(d1[node], node));
				}
				else if(w+weight<d2[node] && w+weight>d1[node])
				{
					d2[node]=w+weight;
					pq.push(pii(w+weight, node));
				}

			}
		}
		printf("Case %d: %d\n", i, d2[n]);
		for(int cl=0;cl<=n;cl++)
            graph[cl].clear();
	}
}








