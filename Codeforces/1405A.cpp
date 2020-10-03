#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		int n;
		cin>>n;

		std::vector<int> v;

		for( int i=0;i<n;i++ )
		{
			int p;
			cin>>p;

			v.push_back(p);
		}

		reverse( v.begin(), v.end() );

		for( auto x: v )
			cout<<x<<" ";

		cout<<"\n";
	}
}