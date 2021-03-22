#include <bits/stdc++.h>
#define mx 891917
#define ll long long
using namespace std;

int sum[6][mx];
int dp[mx];

int grundy(ll n)
{
	if(n<mx and dp[n])
		return dp[n];

	int r= sqrt(n);
	int l= sqrt(sqrt(n));

	if(r>=n)
		r--;
	if( l*1LL*l*l*l==n )
		l--;

	int ret= 0;

	while(1)
		if( sum[ret][r]-sum[ret][l]<=0 )
			break;
		else
			ret++;

	if(n<mx)
	{
		for( int i=0;i<6;i++ )
			sum[i][n]= sum[i][n-1];
		sum[ret][n]++;
		dp[n]= ret;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for( int i=1;i<mx;i++ )
		int p= grundy(i);

	int n;
	cin>>n;

	ll arr[n+5];
	int ans= 0;

	for( int i=0;i<n;i++ )
		cin>>arr[i], ans^= grundy(arr[i]);

	if(ans)
		cout<<"Furlo\n";
	else
		cout<<"Rublo\n";
}