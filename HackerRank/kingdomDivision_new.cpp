#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int n;
std::vector<int> adj[100007];
int dp[100007][2][2];
int vis[100007][2][2];

int rec( int u, int p, int col, bool same )
{
	if( vis[u][col][same] )
		return dp[u][col][same];

	int niboBaNiboNa= 1, kaukeiNiboNa= 1;

	for( auto v: adj[u] )
	{
		if(v==p)
			continue;

		int x= ( 0LL+rec( v,u,col,1 )+rec( v,u,1-col,0 ) )%mod;
		niboBaNiboNa= ( 1LL*niboBaNiboNa*x )%mod;
		int y= rec( v,u,1-col,0 );
		kaukeiNiboNa= ( 1LL*kaukeiNiboNa*y )%mod;
	}

	int ret;

	if( same )
		ret= niboBaNiboNa;
	else
		ret= (0LL+niboBaNiboNa-kaukeiNiboNa+mod)%mod, ret= (ret+mod)%mod;

	vis[u][col][same]= 1;

	return dp[u][col][same]= ret;
}

int main()
{
	cin>>n;

	for( int i=1;i<n;i++ )
	{
		int u,v;
		cin>>u>>v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cout<< (rec( 1,1,0,0 )+rec( 1,1,1,0 ))%mod <<"\n";
	// cout<<st.size()<<endl;
}