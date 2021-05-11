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

		if( n<3 )
		{
			cout<<"-1\n";
			continue;
		}

		cout<<n-1<<"\n";
		cout<<"1 2\n";

		for( int i=3;i<=n;i++ )
			cout<<"1 "<<i<<"\n";

		cout<<"1\n";
	}
}