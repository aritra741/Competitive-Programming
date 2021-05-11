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
		string s,p;
		cin>>s>>p;

		map<char,int>mp;
		char pore= 'z'+1;

		for(auto c: s)
			mp[c]++;

		for( auto c: p )
		{
			mp[c]--;

			if(pore>'z' and c!=p[0])
				pore= c;
		}

		for( char c='a';c<p[0];c++ )
			while(mp[c])
				cout<<c, mp[c]--;

		if( pore<p[0] )
		{
			cout<<p;

			while(mp[p[0]])
				mp[p[0]]--, cout<<p[0];
		}
		else
		{
			while(mp[p[0]])
				mp[p[0]]--, cout<<p[0];
			
			cout<<p;
		}

		for( char c=(int)p[0]+1;c<='z';c++ )
			while(mp[c])
				cout<<c, mp[c]--;
		
		cout<<"\n";
	}
}