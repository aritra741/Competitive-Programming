#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll n,k,d;
	cin>>n>>k>>d;

	int ans[n+5][d+5];

	ll x= 1, cnt= 0;

	while(x<=n and cnt<d)
		x*= k, cnt++;

	if(x<n)
		return cout<<"-1\n", 0;

	for( int i=0;i<n;i++ )
	{
		int p= i;
		for( int j=0;j<d;j++ )
		{
			ans[i][j]= (p%k)+1;
			p/= k;
		}
	}

	for( int i=0;i<d;i++ )
	{
		for( int j=0;j<n;j++ )
			cout<<ans[j][i]<<" ";

		cout<<"\n";
	}
}