#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		string s;
		cin>>s;

		map<char,int>mp;

		for( auto c: s )
			mp[c]++;

		if( mp['E'] and mp['L']>1 and mp['T']>1 and mp['I']>1 and mp['M']>1 )
		{
			if( s.size()==9 or mp['E']>1 )
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
		else
			cout<<"NO\n";
	}
}