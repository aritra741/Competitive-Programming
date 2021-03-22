#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007
#define pii pair<int,int>
#define pci pair<int,int>
#define ff first
#define ss second
#define piii pair<int,pii>
#define mx 200007
using namespace std;

int n;
std::vector<pii> v[mx];

ll dp[mx][11];
bool vis[mx][11];


ll rec( int i, int m )
{
	if( i>=n )
		return 0;
	if( vis[i][m] )
		return dp[i][m];

	std::vector<int> one,two,three;

	for( auto x: v[i] )
	{
		if(x.ff==1)
			one.push_back(x.ss);
		else if(x.ff==2)
			two.push_back(x.ss);
		else
			three.push_back(x.ss);
	}

	sort( one.begin(), one.end(), greater<int>() );
	sort( two.begin(), two.end(), greater<int>() );
	sort( three.begin(), three.end(), greater<int>() );
	
	std::vector<pii> vv;

	for( int j=0;j<min(3,(int)one.size());j++ )
		vv.push_back({1,one[j]});
	for( int j=0;j<min(1,(int)two.size());j++ )
		vv.push_back({2,two[j]});
	for( int j=0;j<min(1,(int)three.size());j++ )
		vv.push_back({3,three[j]});
		
	ll ret= 0;

	sort( vv.begin(), vv.end() );

	do{

		int tot= 0;
		ll sum= 0;
		int mm= m;

		for( int j=0;j<vv.size();j++ )
		{
			if(tot+vv[j].ff>3)
				continue;
			tot+= vv[j].ff;
			mm= (mm+1)%10;
			sum+= vv[j].ss;
			
			if(!mm)
				sum+= vv[j].ss;

			ret= max( ret, sum+rec( i+1, mm ) );
		}

	}while(next_permutation(vv.begin(), vv.end()));

	vis[i][m]= 1;

	return dp[i][m]= ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	for( int i=0;i<n;i++ )
	{
		int k;
		cin>>k;

		for( int j=0;j<k;j++ )
		{
			int x,y;
			cin>>x>>y;

			v[i].push_back(pii(x,y));
		}
	}

	cout<< rec( 0, 0 );
}