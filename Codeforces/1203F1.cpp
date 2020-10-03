#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

/// https://codeforces.com/blog/entry/69108?#comment-535157

bool cmp( pii a, pii b )
{
    return a.first+a.second>b.first+b.second;
}

int main()
{
	int n,r;
	cin>>n>>r;

	vector<pii> pos, neg;

	for( int i=0;i<n;i++ )
	{
		int a,b;
		cin>>a>>b;

		if(b>=0)
			pos.push_back({a,b});
		else
			neg.push_back({a,b});
	}

	sort( pos.begin(), pos.end() );
	sort( neg.begin(), neg.end(), cmp );

	for( auto x: pos )
	{
		if(r<0)
			return cout<<"NO\n", 0;
		if( x.first<=r )
			r+= x.second;
		else
			return cout<<"NO\n", 0;
		if(r<0)
			return cout<<"NO\n", 0;
	}

	for( auto x: neg )
	{
		if(r<0)
			return cout<<"NO\n", 0;
		if( x.first<=r )
			r+= x.second;
		else
			return cout<<"NO\n", 0;
	}
	
	if(r<0)
		return cout<<"NO\n", 0;

	cout<<"YES\n";
}