#include <bits/stdc++.h>
#define mx 1000007
using namespace std;

int dp[mx][2];
bool vis[mx][2];

int n;
string s;

int rec( int i, int carry )
{
	if( i==n )
		return carry;

	if( vis[i][carry] )
		return dp[i][carry];

	int ret= 1e9;

	for( int j=0;j<=9;j++ )
	{
		int sum= s[i]-'0'+j+carry;
		int k= 0;

		if(sum>9)
			k= 1, sum%= 10;

		ret= min( ret, j+sum+rec( i+1, k ) );
		// cout<<i<<" "<<j<<" "<<carry<<" "<<sum+rec( i+1, k )<<endl;
	}

	vis[i][carry]= 1;

	return dp[i][carry]= ret;
}

int main()
{
	cin>>s;

	n= s.size();
	reverse( s.begin(), s.end() );

	cout<< rec(0,0);
}