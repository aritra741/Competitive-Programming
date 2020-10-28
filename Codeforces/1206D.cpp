#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define pii pair<int,int>
#define mx 100107
using namespace std;

std::vector<int> adj[mx];
bool mat[150][150];
std::vector<pii> edge;
bool vis[mx];
int dist[mx], par[mx];
int n;
int ans= 1e9;

void bfs(int x, int y)
{
	for( int i=0;i<n;i++ )
		vis[i]= 0, dist[i]= 1e9, par[i]= -1;

	dist[x]= 0;
	queue<int>q;
	q.push(x);

	while(!q.empty())
	{
		int u= q.front();
		q.pop();

		for( auto v: adj[u] )
		{
			if( vis[v] or (u==x and y==v) )
				continue;

			vis[v]= 1;
			dist[v]= dist[u]+1;

			if( mat[v][x] and dist[v]>1 )
				ans= min( ans, dist[v]+1 ); 

			q.push(v);
		}
	}
}

int main()
{
	cin>>n;

	ll arr[n+5];

	if( n<3 )
		return cout<<"-1", 0;

	map<int,int>mp;
	bool f= 0;

	int cnt= 0;

	for( int i=0;i<n;i++ )
	{
		ll x;
		cin>>x;

		if(!x)
			continue;

		arr[cnt++]= x;

		for( ll j=0;j<61;j++ )
			if( x&(1LL<<j) )
			{
				mp[j]++;

				if( mp[j]>=3 )
					f= 1;
			}
	}

	if(f)
		return cout<<"3\n", 0;

	n= cnt;

	for( int i=0;i<n;i++ )
		for( int j=i+1;j<n;j++ )
		{
			for( int k=0;k<61;k++ )
				if( arr[i]&(1LL<<k) and arr[j]&(1LL<<k) )
				{
					mat[i][j]= 1;
					mat[j][i]= 1; 
					adj[i].push_back(j);
					adj[j].push_back(i);
					edge.push_back(pii(i,j));
				}
		}


	for( auto x: adj[0] )
	{
		if( x==4 )
		{
			bfs(4,3);
			bfs(3,4);

			
		}
	}

	for( auto x: edge )
	{
		int u= x.ff;
		int v= x.ss;
		
		bfs(u,v);
		bfs(v,u);
		
	}

	if(ans>n+100)
		ans= -1;

	cout<< ans <<"\n";
}