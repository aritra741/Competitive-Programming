#include <bits/stdc++.h>
using namespace std;

int dp[3500];

int rec( int n )
{	
	if(n<=0)
		return 0;

	if(dp[n]!=-1)
		return dp[n];

	bitset<3337>bt;
	bt.set();

	for( int i=1;i<=n;i++ )
	{
		bt[ rec( i-3 )^rec( n-i-2 ) ]= 0;
	}

	return dp[n]= bt._Find_first();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(dp,-1,sizeof(dp));

	int tc;
	cin>>tc;

	while(tc--)
	{
		int n;
		cin>>n;

		if(rec(n))
			cout<<"Joker\n";
		else
			cout<<"Bane\n";
	}
}