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

		int x;
		bool f= 1;

		for( int i=1;i<=n;i++ )
		{
			cin>>x;

			if(i%x)
				f= 0;
		}

		if(f)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}