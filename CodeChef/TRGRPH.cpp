#include <bits/stdc++.h>
#define N 100007
using namespace std;

int ind[N], subtree[N], sub[N];
bool vis[N];
std::vector<int> adj[N];

bool cmp( int a, int b )
{
	return ind[a]>ind[b];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin>>q;

	while(q--)
	{
		int n,m;
		cin>>n>>m;

		for( int i=1;i<=n;i++ )
			ind[i]= 0, subtree[i]= 0, adj[i].clear(), vis[i]= 0, sub[i]= 0;

		int mx= 0, node= 0;

		for( int i=0;i<m;i++ )
		{
			int u,v;
			cin>>u>>v;

			ind[u]++;
			ind[v]++;

			if(ind[u]>mx)
				mx= ind[u], node= u;
			if(ind[v]>mx)
				mx= ind[v], node= v;

			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for( int i=1;i<=n;i++ )
			sort( adj[i].begin(), adj[i].end(), cmp );

		queue<int>q;

        int arr[n+5];

        for( int i=0;i<n;i++ )
        	arr[i]= i+1;

        sort( arr, arr+n, cmp );
        node= 0;

        for( int i=0;i<n;i++ )
        	if(ind[i+1])
        	{
        		if(!node)
        			node= arr[i];
        		q.push(arr[i]);
        	}

        bool f= 1;

		while(!q.empty())
		{
			int u= q.front();
			vis[u]= 1;

			if(!subtree[u] and u!=node)
			{
				f= 0;
				break;
			}
			// cout<<u<<" "<<subtree[u]<<endl;
			q.pop();

			for( auto v: adj[u] )
			{
				if(!vis[v])
				{
					if( subtree[v]!=subtree[u] )
					{
						f= 0;
						break;
					}
					sub[v]++;
					subtree[v]= u;
				}
			}
		}

		for( int i=1;i<=n and m;i++ )
			if( !vis[i] )
				f= 0;
		if( !m and n>1 )
			f= 0;

		if(!f)
		{
			cout<<"NO\n";
			continue;
		}

		cout<<"YES\n";

		for( int i=1;i<n;i++ )
			cout<<subtree[i]<<" ";
		cout<<subtree[n]<<"\n";
	}
}
