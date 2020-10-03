#include <bits/stdc++.h>
#define mx 300007
using namespace std;

std::vector<int> v[mx];
int ans[mx];
bool ex[mx];

int main()
{
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);

	int tc;
	cin>>tc;

	while(tc--)
	{
		int n;
		cin>>n;

		int arr[n+5];

		ans[0]= n+1;
		for( int i=1;i<=n;i++ )
			v[i].clear(), v[i].push_back(0), ans[i]= n+1, ex[i]= 0;

		for( int i=1;i<=n;i++ )
			cin>>arr[i], v[arr[i]].push_back(i), ex[arr[i]]= 1;

		for( int i=1;i<=n;i++ )
			v[i].push_back(n+1);

		for( int i=1;i<=n;i++ )
		{
			if(!ex[i])
				continue;

			int val= 0;
			for( int j=1;j<v[i].size();j++ )
				val= max( val, v[i][j]-v[i][j-1] );
			ans[val]= min( ans[val], i );
		}

		for( int i=1;i<=n;i++ )
			ans[i]= min( ans[i], ans[i-1] ), cout<< ((ans[i]<=n)?ans[i]:-1) <<" ";

		cout<<"\n";
	}
}