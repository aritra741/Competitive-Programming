#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int dp[2][(1<<24)+7];

int main()
{
	fast;

	int n;
	cin>>n;

	for( int i=0;i<n;i++ )
	{
		string s;
		cin>>s;

		int now= 0;  

		for( auto c: s )
			now|= ( 1<<(c-'a') );

		dp[0][now]++;
	}

	int f= 1;

	for( int i=1;i<=24;i++ )
	{
		for( int mask=0;mask<(1<<24);mask++ )
		{
			if( !(mask&(1<<(i-1))) )
				dp[f][mask]= dp[!f][mask];
			else
				dp[f][mask]= dp[!f][mask]+dp[!f][mask^(1<<(i-1))];
		}

		f= !f;
	}

	long long ans= 0;

	for( int i=0;i<(1<<24);i++ )
	{
		long long now= 0;

		for( int j=0;j<24;j++ )
			if( !(i&(1<<j)) )
				now+= 1<<j;

		now= n-dp[0][now];

		ans^= 1LL*now*now;
	}

	cout<< ans <<"\n";
}