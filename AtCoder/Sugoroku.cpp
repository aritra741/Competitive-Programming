#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define ff first
#define ss second
#define inf 1000000000000LL
using namespace std;

int n,m;
string s;

deque<pii>dq;
ll dp[100007];
int st[100007];

int main()
{
	cin>>n>>m;
	cin>>s;

	for( int i=1;i<=n;i++ )
		dp[i]= inf;

	dq.push_back({0,0});
	for( int i=1;i<=n;i++ )
	{
		if(s[i]=='1')
			continue;

		while( dq.size() and dq.front().ff<i-m ) dq.pop_front();
		while( dq.size() and dq.back().ss>=dp[i] ) dq.pop_back();
		
		if(dq.size())
			dp[i]= dq.front().ss+1, st[i]= i-dq.front().ff;

		dq.push_back({i,dp[i]});
	}

	if(dp[n]>n)
		cout<<"-1\n";
	else
	{
		std::vector<int> v;
		while(n>0)
			v.push_back(st[n]), n-= st[n];

		reverse(v.begin(), v.end());

		for( auto x: v )
			cout<<x<<" ";
	}
}