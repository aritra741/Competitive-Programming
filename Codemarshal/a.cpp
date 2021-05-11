#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define ff first
#define ss second
#define lchild 2*node
#define rchild lchild+1
#define mid (l+r)/2
#define mx 400007
#define mod 998244353
#define sf(x) scanf("%d", &x);
using namespace std;

int par[mx], sz[mx];

void init()
{
	for( int i=0;i<mx;i++ )
		par[i]= i, sz[i]= 1;
}

int Find( int u )
{
	if(u==par[u])
		return u;
	return par[u]= Find(par[u]);
}

void unite( int u, int v)
{
	int paru= Find(u);
	int parv= Find(v);

	if(paru!=parv)
	{
		if( sz[paru]>sz[parv] )
			sz[paru]+= sz[parv], par[parv]= paru;
		else
			sz[parv]+= sz[paru], par[paru]= parv;
	}
}

bool cmp( pii a, pii b )
{
	if( a.ss==b.ss )
		return a.ff<b.ff;
	return a.ss<b.ss;
}

ll Pow( ll x, ll y )
{
	ll res= 1;

	while(y>0)
	{
		if(y&1)
			res= (res*x)%mod;
		x= (x*x)%mod;
		y>>= 1;
	}

	return res;
}

int main()
{
	// fast;

	int tc;
	cin>>tc;

	while(tc--)
	{
		init();

		int c,n,m;
		cin>>c>>n>>m;

		std::vector<pii> vv[c+5], v;
		map<int,int>mp, ulta;

		for( int i=0;i<c;i++ )
		{
			int x;
			cin>>x;

			int last= 0;

			for( int j=0;j<x;j++ )
			{
				int p,q;
				cin>>p>>q;

				vv[i].push_back({p,q});

				// unite(p,q);
				v.push_back({p,q});

				mp[p];
				mp[q];
			}
		}

		int cnt= 0;

		for( auto x: mp )
			mp[x.first]= ++cnt, ulta[cnt]= x.first;

		for( int i=0;i<c;i++ )
		{
			int last= 0;

			for( auto &x: vv[i] )
			{
				x.ff= mp[x.ff];
				x.ss= mp[x.ss];
			}

			for( auto x: vv[i] )
			{
				unite(x.ff,x.ss);

				if(last)
					unite(x.ff, last);

				last= x.ss;
			}
		}


		ll ans= 1;
		int last= 0;
		int cov= n;

		sort( v.begin(), v.end() );

		int lf= 0, ls= 0;

		for( auto x: v )
		{
			int nf= x.ff;
			int ns= x.ss;

//            cout<<nf<<" "<<ns<<" "<<lf<<" "<<ls<<endl;
//            cout<<" "<<ulta[lf]<<" "<<ulta[nf]<<endl;
			if( lf and nf<=ls and nf>=lf )
				unite( mp[lf], mp[nf] ), ls= max(ls, ns);
			else
				lf= nf, ls= ns;

			int shesh= max(last+1,x.ff);
			cov-= max(0,x.ss-shesh+1);
			last= max( last, x.ss );

			// cout<<x.ff<<" "<<x.ss<<" "<<x.ss-shesh+1<<" "<<shesh<<endl;
		}

		int pl= 0;
//        cout<<"ashe\n";
		for( auto x: mp )
			if( Find(x.ss)==x.ss )
				pl++;

		ans= Pow( m, cov+pl );

		cout<<ans<<"\n";
	}
}
