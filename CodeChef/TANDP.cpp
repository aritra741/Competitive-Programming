#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main()
{
	fast;
	int tc;
	cin>>tc;

	while(tc--)
	{
		int n,m;
		cin>>n>>m;

		int x,y;
		cin>>x>>y;

		int a,b;
		cin>>a>>b;

		int chor= n-x+m-y;
		int police= max( n-a, m-b );

		if(police<chor)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
}