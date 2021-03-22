#include <bits/stdc++.h>
#define ll long long
#define mx 100007
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin>>tc;

	for( int tt=1;tt<=tc;tt++ )
	{
		string s;
		cin>>s;

		int agey=0,pore=0;

		for( auto c: s )
			if(c=='W')
				pore++;

		int ans= 0;
		int baad= 0;

		for( int i=0;i<s.size();i++ )
		{
			char c= s[i];

			if(c=='W')
			{
				if(baad>0)
					baad--;
				else
					agey++, pore--;
			}

			else if( c=='O' and (agey>0 and pore>0) )
				agey--, baad++, pore--, ans++;
		}

		cout<<"Case "<<tt<<": "<<ans<<"\n";		
	}
}
