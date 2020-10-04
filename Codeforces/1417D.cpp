#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		int n;
		cin>>n;

		int arr[n+7];
		int s= 0;

		for( int i=1;i<=n;i++ )
			cin>>arr[i], s+= arr[i];

		if(s%n)
		{
			cout<<"-1\n";
			continue;
		}

		vector<int> vi, vj, vx;

		for( int i=2;i<=n;i++ )
		{
			int lagbe= ( i-arr[i]%i )%i;

			if(lagbe)
				vi.push_back( 1 ),
				vj.push_back( i ),
				vx.push_back( lagbe );

			vi.push_back( i ),
			vj.push_back( 1 ),
			vx.push_back( (arr[i]+lagbe)/i );
		}

		for( int i=2;i<=n;i++ )
			vi.push_back( 1 ),
			vj.push_back( i ),
			vx.push_back( s/n );

		cout<<vi.size()<<"\n";

		for( int i=0;i<vi.size();i++ )
			cout<< vi[i] <<" "<< vj[i] <<" "<<vx[i] <<"\n";
	}
}