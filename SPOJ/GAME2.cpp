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

		int ans= 0;
		map<int,int>mp;

		for( int i=0;i<n;i++ )
		{
			int x;
			cin>>x;

			ans^= x;

			for( int j=0;j<30;j++ )
				if( x&(1<<j) )
					mp[j]++;
		}

		if(!ans)
			cout<<"0\n";
		else
			for( int i=30;i>=0;i-- )
				if( mp[i]&1 )
				{
					cout<<mp[i]<<"\n";
					break;
				}
	}
}