#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int dp[2][(1<<22)+7];

int main()
{
	fast;

	int n;
	cin>>n;

	int arr[n+5];

	for( int i=0;i<n;i++ )
	{
		cin>>arr[i];

		dp[0][arr[i]]= arr[i];
	}	

	int f= 1;

	for( int i=1;i<=22;i++ )
	{
		for( int y=0;y<(1<<22);y++ )
		{
			if( y&(1<<(i-1)) )
				dp[f][y]= dp[f^1][y]?dp[f^1][y]:dp[f^1][y^(1<<(i-1))];
			else
				dp[f][y]= dp[f^1][y];
		}

		f^= 1;
	}

	for( int i=0;i<n;i++ )
	{
		int y= 0;

		for( int j=0;j<22;j++ )
			if( !(arr[i]&(1<<j)) )
				y+= 1<<j;

		if(!dp[0][y])
			dp[0][y]= -1;

		cout<<dp[0][y]<<" ";
	}
}