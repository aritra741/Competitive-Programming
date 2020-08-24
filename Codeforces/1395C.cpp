#include <bits/stdc++.h>
using namespace std;

int arr[520], brr[520];
int dp[520][520];
bool vis[520][520];
int n,m;

int rec( int i, int mask )
{
	if( i>=n )
		return mask;
	if( vis[i][mask] )
		return dp[i][mask];

	int ret= 1e9;
	for( int j=0;j<m;j++ )
		ret= min( ret, rec( i+1, mask|( arr[i]&brr[j] ) ) );

	vis[i][mask]= 1;

	return dp[i][mask]= ret;
}

int main()
{
	cin>>n>>m;

	for( int i=0;i<n;i++ )
		cin>>arr[i];
	for( int i=0;i<m;i++ )
		cin>>brr[i];
	
	cout<< rec( 0, 0 ) <<endl;
}
