#include <bits/stdc++.h>
using namespace std;

char mp[300007];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin>>tc;

	while(tc--)
	{
		int n,k;
		cin>>n>>k;

		string s;
		cin>>s;

		int zz= 0, oo= 0;

		for( int i=0;i<k;i++ )
			mp[i]= s[i], zz= (s[i]=='0')?zz+1:zz, oo= (s[i]=='1')?oo+1:oo;

		bool f= 1;
		for( int i=k;i<n;i++ )
			if( mp[i%k]!=s[i] and mp[i%k]!='?' and s[i]!='?' )
				f= 0;
			else
			{	
				if(s[i]=='?')
					continue;
				if( mp[i%k]=='?' )
				{
					if(s[i]=='1')
						oo++;
					else
						zz++;
				}
				mp[i%k]= s[i];
			}

		if(!f)
		{
			cout<<"NO\n";
			continue;
		}

		if( oo>k/2 or zz>k/2 )
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
}
