#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--)
	{
		int n;
		cin >> n;

		string s, p;
		cin >> s >> p;

		std::vector<int> zer;

		for( int i=0;i<n;i++ )
			if( s[i]!=p[i] )
				if( s[i]=='0' )
					zer.push_back(i);

		reverse( zer.begin(), zer.end() );

		for( int i=0;i<n;i++ )
		{
			if( s[i]!=p[i] )
			{
				if( s[i]=='1' )
				{
					if( zer.empty() or zer.back()<i )
						break;
					swap( s[zer.back()], s[i] );
					zer.pop_back();
				}
			}
		}

		if(s==p)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}