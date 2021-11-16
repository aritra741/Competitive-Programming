#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define mod 1000000007
#define yes() cout<<"Yes\n"
#define no() cout<<"No\n"
#define mod 1000000007
#define ll long long
#define mx 200007
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define ff first
#define ss second
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

map<string,int>stint;
map<int,string>intst;
std::vector<int> adj[200007];
map<int,int>mat[200007], ulta[200007];
vector< vector<string> > ret;
bool mark[507], point[200007];

void dfs( int u, vector<string>& ans )
{
	// cout<<u<<"\n";

	if( u>1 )
		ans.push_back( intst[u] ),
		ret.push_back( ans );

	// for( auto x: ans )
	// 	cout<<" "<<x<<endl;

	for( auto v: adj[u] )
	{
		// cout<<v<<" "<<mat[u][v]<<" "<<point[v]<<" "<<mark[ mat[u][v] ]<<endl;
		if( !mat[u][v] )
			continue;

		if( point[v] and mark[ mat[u][v] ] )
			continue;

		dfs( v, ans );
	}

	if(u>1)
		ans.pop_back();
}

vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
	
	int cnt= 2, pt= 0;

	for( auto x: paths )
	{
		int last= 1;
		pt++;

		for( auto y: x )
		{
			if( !stint[y] )
				stint[y]= cnt, intst[cnt++]= y;
			
			if(!mat[last][stint[y]])
				adj[last].push_back(stint[y]);

			mat[last][stint[y]]= pt;

			if(last>1)
				ulta[stint[y]][last]= pt;
			
			last= stint[y];
		}
	}


	for( int i=2;i<cnt;i++ )
	{
		if(ulta[i].size()<2)
			continue;

		for( auto x: ulta[i] )
		{
			point[x.first]= 1;
			mark[mat[x.first][i]]= 1;
			mat[x.first][i]= 0;
		}
	}

	vector<string>ss;

	dfs(1,ss);

	// for( auto x: ret )
	// {
	// 	for( auto y: x )
	// 		cout<<y<<" ";

	// 	cout<<endl;
	// }

	return ret;
}

int main()
{
//	fast;

	std::vector< vector<string> > v;

	std::vector<string> x;
	x.push_back("a");
	x.push_back("b");
	v.push_back(x);
	x.clear();
	x.push_back("a");
	v.push_back(x);
	x.clear();
	x.push_back("c");
	v.push_back(x);
	x.clear();
	x.push_back("d");
	v.push_back(x);
	x.clear();
	x.push_back("c");
	x.push_back("b");
	v.push_back(x);
	x.clear();
	x.push_back("d");
	x.push_back("a");
	v.push_back(x);
	x.clear();
	
	
	deleteDuplicateFolder(v);
}
