#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		int n;
		cin>>n;

		ll arr[n+5];

		for( int i=0;i<n;i++ )
			cin>>arr[i];

		bool f= 1;
		for( ll x=50;x>=0;x-- )
		{
			int o= 0, z= 0;
			for( int i=0;i<n;i++ )
				if( arr[i]&(1LL<<x) )
					o++;
				else
					z++;

			if( o%2==0 )
				continue;

			if( o%4==1 )
			{
				f= 0;
				cout<<"WIN\n";
				break;
			}	

			if( o%4==3 )
			{
				f= 0;
				if( z%2==0 )
					cout<<"LOSE\n";
				else
					cout<<"WIN\n";
				break;;
			}	
		}

		if(f)
			cout<<"DRAW\n";
	}
}