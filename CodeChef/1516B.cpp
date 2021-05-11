#include <bits/stdc++.h>
using namespace std;

int val( int n )
{
	return (n*(n+1))/2;
}

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		int n,m,k;
		cin>>n>>m>>k;

		int tot= val(n-1)+val(m-1);

		if(tot==k)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}