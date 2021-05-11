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
		int n,x,y=0,z=2e9,p=-1;
		cin>>n;

		int cnt= 0;

		for( int i=0;i<n;i++ )
		{
			cin>>x;

			if(!y)
				z= x;

			if(x<y)
				cnt++;

			y= x;
		}

		if(cnt==1 and x<=z)
			cout<<"YES\n";
		else if(cnt==0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}