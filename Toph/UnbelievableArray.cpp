#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define mx 200007
using namespace std;

int par[mx];
int val[mx];

int Find(int u)
{
	if(par[u]==u)
		return u;
	return par[u]= Find(par[u]);
}

void unite( int u, int v )
{
	int paru= Find(u);
	int parv= Find(v);

	cout<<u<<" "<<paru<<" "<<v<<" "<<parv<<endl;

	par[paru]= parv;


}

void init()
{
	for( int i=0;i<mx;i++ )
		par[i]= i, val[i]= 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin>>tc;

	for( int t=1;t<=tc;t++ )
	{
		int n,q;
		cin>>n>>q;

		init();

		int arr[n+5];

		for( int i=1;i<=n;i++ )
		{
			cin>>arr[i];

			val[arr[i]]++;

			unite( i, arr[i]+n );
			// cout<<i<<" "<<Find(i,0)<<endl;
		}

		cout<<"Case "<<t<<":\n";

		while(q--)
		{
			int tp;
			cin>>tp;

			if(tp==1)
			{
				int x,y;
				cin>>x>>y;

				if(!val[x])
					continue;

				val[y]++;

				if(y!=x)
					val[x]= 0;
				else
					continue;

				unite( x, y );
			}
			else
			{
				int idx;
				cin>>idx;

				int now= Find(arr[idx]);

				cout<< now <<"\n";
			}
		}
	}
}