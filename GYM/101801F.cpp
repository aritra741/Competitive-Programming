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
		int n;
		cin>>n;

		int ans= 2e9;
		int xx= 0;

		for( int i=0;i<n;i++ )
		{
			int x;
			cin>>x;

			xx^= x;

			for( int j=0;j<31;j++ )
				if(x&(1<<j))
				{
					ans= min(1<<j,ans);
					break;
				}
		}

		cout<<xx<<endl;

		if(xx)
			ans= 0;

		cout<< ans <<"\n";
	}
}