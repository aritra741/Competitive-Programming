#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		int n,m;
		cin>>n>>m;

		int arr[n+5][m+5];
		int cnt= 0, mn= 1e9,z= 0;
		int sum= 0;

		for( int i=0;i<n;i++ )
			for( int j=0;j<m;j++ )
			{
				cin>>arr[i][j];
				
				sum+= abs(arr[i][j]);
				mn= min( mn, abs(arr[i][j]) );

				if(!arr[i][j])
					z++;
				else if(arr[i][j]<0)
					cnt++;
			}

		if(cnt&1 and !z)
			sum-= mn*2;

		cout<<sum<<endl;
	}
}