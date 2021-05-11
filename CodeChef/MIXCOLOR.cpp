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

		map<int,int>mp;
		int ans= 0;

		for( int i=0;i<n;i++ )
		{
			int x;
			cin>>x;

			mp[x]++;

			if(mp[x]>1)
				ans++;
		}

		cout<< ans <<"\n";
	}
}