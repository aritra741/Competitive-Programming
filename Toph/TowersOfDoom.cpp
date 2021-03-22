#include <bits/stdc++.h>
using namespace std;

int lcm( int a, int b )
{
	return (max(a,b)/__gcd(a,b))*min(a,b);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin>>tc;

	for( int t=1;t<=tc;t++ )
	{
		int n,s;
		cin>>n>>s;

		int arr[n+5], ss[s+5];

		for( int i=0;i<n;i++ )
			cin>>arr[i];

		for( int i=0;i<s;i++ )
			cin>>ss[i];

		int ans= 0;

		for( int i=0;i<n;i++ )
		{
			int tot= 0;

			for( int j=1;j<(1<<s);j++ )
			{
				int lb= 1;

				for( int k=0;k<s;k++ )
					if( j&(1<<k) )
						lb= lcm(lb,ss[k]);

				if( __builtin_popcount(j)&1 )
					tot+= arr[i]/lb;
				else
					tot-= arr[i]/lb;
			}

			tot++;

			// cout<<i<<" "<<tot<<endl;

			ans^= tot;
		}

		cout<<"Case "<<t<<": ";

		if(ans)
			cout<<"Alice\n";
		else
			cout<<"Bob\n";

	}

}