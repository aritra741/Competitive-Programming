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
		int n,m;
		cin>>n>>m;

		string s[n+5];

		for( int i=0;i<n;i++ )
			cin>>s[i];

		bool f= 1;

		for( int i=0;i<n;i++ )
			for( int j=0;j<m;j++ )
			{	
				if( s[i][j]=='A' )
				{
					if( i and s[i-1][j]!='A' )
					{
						f= 0;
						break;
					}
				}
				else if( s[i][j]=='W' )
				{
					if( !j or j==m-1 or s[i][j-1]=='A' or s[i][j+1]=='A' )
					{
						f= 0;
						break;
					}
					if( i and s[i-1][j]=='B' )
					{
						f= 0;
						break;
					}
				}
			}

		if(f)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
}