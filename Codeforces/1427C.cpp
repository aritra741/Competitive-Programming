#include <bits/stdc++.h>
#define mx 100007
using namespace std;

int t[mx], x[mx], y[mx];
int dp[mx], suff[mx];

int main()
{
	int r,n;
	cin>>r>>n;

	x[0]= 1;
	y[0]= 1;

	for( int i=1;i<=n;i++ )
		cin>>t[i]>>x[i]>>y[i], dp[i]= 1;

	for( int i=n;i>=0;i-- )
	{
		for( int j=i+1;j<=n;j++ )
		{
			if( abs( x[j]-x[i] )+abs( y[j]-y[i] )>t[j]-t[i] )
				continue;

			dp[i]= max( dp[i], dp[j]+1 );

			if( t[j]-t[i]>=2*r )
			{
				dp[i]= max( dp[i], suff[j]+1 );
				break;
			}
		}

		suff[i]= max( suff[i+1], dp[i] );
	}

	cout<< max(0,dp[0]-1) <<"\n";
}