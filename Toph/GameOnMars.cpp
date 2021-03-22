#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin>>tc;

	for( int t=1;t<=tc;t++ )
	{
		int n;
		cin>>n;

		int ans= 0;
		int arr[n*3+5];
		int idx= 0;

		for( int i=1;i<=n;i++ )
		{
			int x,y;
			cin>>x>>y;

			x--, y--;

			int now= x+1;
			now^= (y+1);

			ans^= now+1;

			arr[idx++]= x+1;
			arr[idx++]= y+1;
			arr[idx++]= now+1;
		}

		cout<<"Case "<<t<<": ";

		if(ans)
		{
			cout<<"Alice\n";

			for( int i=0;i<idx;i++ )
			{
				if(ans<=)
			}
		}
		else
			cout<<"Bob\n";
	}
}