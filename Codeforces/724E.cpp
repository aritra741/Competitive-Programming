#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define mod 1000000007
#define yes() cout<<"Yes\n"
#define no() cout<<"No\n"
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define ff first
#define ss second
#define ld long double
#define mx 10007
using namespace std;

ll dp[2][mx+7];
bool vis[2][mx+7];
ll s[mx+7], p[mx+7], c; 

int main()
{
	int n;
	cin>>n>>c;

	for( int i=1;i<=n;i++ )
		cin>>p[i];
	for( int i=1;i<=n;i++ )
		cin>>s[i];
	
	ll ans= 1e18;

	for( int i=1;i<=n;i++ )
	{
		int ii= i%2;

		for( int j=0;j<=i;j++ )
		{
			dp[ii][j]= 1e18;

			if(j)
				dp[ii][j]= dp[ii^1][j-1]+s[i];
			if(j<i)
				dp[ii][j]= min(dp[ii][j], dp[ii^1][j]+p[i]+j*c);

			if( i==n )
				ans= min( ans, dp[ii][j] );
		}
	}

	cout<< ans;
}