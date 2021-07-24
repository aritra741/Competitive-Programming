#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		int s;
		cin>>s;

		int ans;

		for( int i=1;;i++ )
		{
			if( i*i>=s )
			{
				ans= i;
				break;
			}
		}

		cout<<ans<<"\n";
	}
}