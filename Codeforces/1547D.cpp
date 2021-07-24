#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define mod 1000000007
#define yes() cout<<"Yes\n"
#define no() cout<<"No\n"
#define mod 1000000007
#define ll long long
#define mx 300007
#define pii pair<int,int>
#define piii pair<int,pii>
#define ff first
#define ss second
using namespace std;

int main()
{
	fast;

	int tc;
	cin>>tc;

	while(tc--)
	{
		int n;
		cin>>n;

		int arr[n+5];

		for( int i=1;i<=n;i++ )
			cin>>arr[i];

		cout<<"0 ";

		for( int i=2;i<=n;i++ )
		{
			int x= arr[i-1];
			int y= arr[i];

			int now= 0;

			for( int j=0;j<30;j++ )
				if( (x&(1<<j)) and !(y&(1<<j)) )
					now+= 1<<j;

			cout<<now<<" ";

			arr[i]= now^y;
		}

		cout<<"\n";
	}
}