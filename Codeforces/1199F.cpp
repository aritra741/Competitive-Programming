#include <bits/stdc++.h>
using namespace std;

int n;
string s[55];
int dp[55][55][55][55];
bool vis[55][55][55][55];

int rec( int x1, int y1, int x2, int y2 )
{
	if( x1==x2 and y1==y2 )
		return (s[x1][y1]=='#');
	if( vis[x1][y1][x2][y2] )
		return dp[x1][y1][x2][y2];

	int ret= max(abs(x2-x1)+1,abs(y2-y1)+1);

	for( int i=x1;i<x2;i++ )
		ret= min( ret, rec( x1, y1, i, y2 )+rec( i+1, y1, x2, y2 ) );
	for( int i=y1;i<y2;i++ )
		ret= min( ret, rec( x1, y1, x2, i )+rec( x1, i+1, x2, y2 ) );
	
	vis[x1][y1][x2][y2]= 1;

	return dp[x1][y1][x2][y2]= ret;
}	

int main()
{
	cin>>n;

	for( int i=0;i<n;i++ )
		cin>>s[i];

	cout<< rec( 0, 0, n-1, n-1 );
}