#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		int n,h,c0,c1;
		cin>>n>>c0>>c1>>h;

		string s;
		cin>>s;
		
		int z= 0, o= 0;

		for( int i=0;i<n;i++ )
		{
			if(s[i]=='0')
				z++;
			else
				o++;
		}

		int ans= o*c1+z*c0;

		for( int i=0;i<=n;i++ )
		{
			int tot= z*c0;
			tot+= o*c1;

			if( i<o )
				tot-= (o-i)*c1, tot+= h*(o-i);
			else
				tot+= (i-o)*c1, tot+= h*(i-o);

			int j= n-i;

			if( j<z )
				tot-= (z-j)*c0;
			else
				tot+= (j-z)*c0;

			ans= min( ans, tot );
		}

		cout<< ans <<endl;
	}
}