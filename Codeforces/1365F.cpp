#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		int n;
		cin>>n;

		map<int,int>mp1, mp2;
		map<pii,int>mpp1, mpp2;
		int a[n+5], b[n+5];

		for( int i=0;i<n;i++ )
			cin>>a[i], mp1[a[i]]++;

		for( int i=0;i<n/2;i++ )
			mpp1[pii(min(a[i],a[n-i-1]), max(a[i],a[n-i-1]))]++;

		for( int i=0;i<n;i++ )
			cin>>b[i], mp2[b[i]]++;

		for( int i=0;i<n/2;i++ )
			mpp2[pii(min(b[i],b[n-i-1]), max(b[i],b[n-i-1]))]++;

		bool f= 1;
		for( auto x: mp2 )
			if( x.second!=mp1[x.first] )
				f= 0;

		for( auto x: mpp2 )
			if( x.second!=mpp1[x.first] )
				f= 0;

		if( n&1 and a[n/2]!=b[n/2] )
			f= 0;

		if(f)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}