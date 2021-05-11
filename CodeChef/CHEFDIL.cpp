#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin>>tc;

	while(tc--)
	{
		string s;
		cin>>s;

		bool fnd= 0;
		int cnt= 0;
		bool f= 1;

		for( auto c: s )
		{
			if( c=='1' )
				cnt++;
		}

		if(cnt&1)
			cout<<"WIN\n";
		else
			cout<<"LOSE\n";
	}
}