#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

/// https://codeforces.com/blog/entry/69108?#comment-535157

bool cmp( pii a, pii b )
{
    return a.first+a.second>b.first+b.second;
}

vector<pii> pos, neg;
int dp[107][60007];
bool vis[107][60007];

int rec( int i, int agey )
{
	if( i>=neg.size() )
		return 0;

	if( vis[i][agey] )
		return dp[i][agey];

	int q1= 0, q2= 0;

	if( agey>=neg[i].first and agey+neg[i].second>=0 )
		q1= 1+rec( i+1, agey+neg[i].second );

	q2= rec( i+1, agey );

	vis[i][agey]= 1;

	return dp[i][agey]= max(q1,q2);
}

int main()
{
	int n,r;
	cin>>n>>r;

	for( int i=0;i<n;i++ )
	{
		int a,b;
		cin>>a>>b;

		if(b>=0)
			pos.push_back({a,b});
		else
			neg.push_back({a,b});
	}

	sort( pos.begin(), pos.end() );
	sort( neg.begin(), neg.end(), cmp );

	int ans= 0;

	for( auto x: pos )
		if( x.first<=r )
			r+= x.second, ans++;

	cout<< ans+rec( 0, r ) <<"\n";
}