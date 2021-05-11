#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin>>tc;

	while(tc--)
	{
		int n,d;
		cin>>n>>d;

		ll sum= 0;
		int arr[n+5];

		std::vector<int> v[2][d+5], pos[2][d+5];

		for( int i=1;i<=n;i++ )
			cin>>arr[i], sum+= arr[i];

		int x= sum/n;

		if( sum%n )
		{
			cout<<"-1\n";
			continue;
		}

		for( int i=1;i<=n;i++ )
			if( arr[i]<x )
				v[0][i%d].push_back(arr[i]), pos[0][i%d].push_back(i);
			else if( arr[i]>x )
				v[1][i%d].push_back(arr[i]), pos[1][i%d].push_back(i);

		ll ans= 0;
		bool f= 1;

		for( int i=0;i<d;i++ )
		{
			int j=0,k=0;

			while(j<v[0][i].size() and k<v[1][i].size())
			{	
				int lagbe= x-v[0][i][j];
				int ase= v[1][i][k]-x;

				v[0][i][j]+= min( lagbe, ase );
				v[1][i][k]-= min( lagbe, ase );
				
				ans+= 1LL*min( lagbe, ase )*(abs(pos[0][i][j]-pos[1][i][k])/d);

				if(v[0][i][j]==x)
					j++;
				if(v[1][i][k]==x)
					k++;
				
				// cout<<v[0][i][j]<<" "<<v[1][i][k]<<" "<<pos[0][i][j]<<" "<<pos[1][i][k]<<endl;
							
			}

			// cout<<i<<"-->";
			for( int p=0;p<v[0][i].size();p++ )
			{
				// cout<<v[0][i][p]<<" ";
				if( v[0][i][p]!=x )
				{
					f= 0;
					// break;
				}
			}
			for( int p=0;p<v[1][i].size();p++ )
			{
				// cout<<v[1][i][p]<<" ";
				if( v[1][i][p]!=x )
				{
					f= 0;
					// break;
				}
			}

			// cout<<endl;
		}

		if(!f)
			ans= -1;

		cout<< ans <<"\n";
	}
}