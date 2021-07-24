#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		int n,a,b;
		cin>>n>>a>>b;

		string s;
		cin>>s;
		
		int cnt= 0, last= 5, x= 0, y= 0;

		for( int i=0;i<n;i++ )
		{
			if( s[i]!=last )
			{
				cnt++;

				if(s[i]=='1')
					x++;
				else
					y++;
			}

			last= s[i];
		}

		if( b>=0 )
			cout<<a*n+b*n<<"\n";
		else
			cout<<a*n+b*(min( x,y )+1)<<"\n";
	}
}