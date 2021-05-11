#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin>>tc;

	while(tc--)
	{
		ll n,k;
		cin>>n>>k;

		if( (n/k)%k!=0 )
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}