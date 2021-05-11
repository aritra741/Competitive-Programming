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
		int n,m,x;
		cin>>n>>m>>x;

		pii arr[n+5];
		int ans[n+5]= {};

		for( int i=0;i<n;i++ )
			cin>>arr[i].ff, arr[i].ss= i;

		sort( arr, arr+n, greater<pii>() );

		priority_queue<pii, vector<pii>, greater<pii> >pq;
		
		for( int i=0;i<m;i++ )
			pq.push(pii(0,i+1));

		int idx= 0;
		bool f= 1;

		while(idx<n)
		{
			pii u= pq.top();
			pq.pop();
			ans[arr[idx].ss]= u.ss;
			pq.push(pii(u.ff+arr[idx++].ff, u.ss));
		}

		std::vector<int> v;

		while(!pq.empty())
			v.push_back(pq.top().ff), pq.pop();

		int mn= 2e9, mx= 0;

		for( auto y: v )
			mn= min( mn, y ), mx= max( mx, y );

		if(mx-mn>x)
		{
			cout<<"NO\n";
			continue;
		}

		cout<<"YES\n";

		for( int i=0;i<n;i++ )
			cout<<ans[i]<<" ";

		cout<<"\n";
	}
}