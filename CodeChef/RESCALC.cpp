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

		int arr[n+5];

		for( int i=0;i<n;i++ )
		{
			int x;
			cin>>x;
			map<int,int>mp;

			arr[i]= x;

			for( int j=0;j<x;j++ )
			{
				int y;
				cin>>y;

				mp[y]++;
			}

			while(1)
			{
				int cc= 0;

				for( auto y: mp )
					if( y.second )
						cc++, mp[y.first]--;

				if(cc==6)
					arr[i]+= 4;
				else if(cc==5)
					arr[i]+= 2;
				else if(cc==4)
					arr[i]++;
				else
					break;
				
				
			}
		}

		int mx= 0, idx= -1;
		int cnt= 0;

		for( int i=0;i<n;i++ )
			if( arr[i]>mx )
				mx= arr[i], idx= i, cnt= 1;
			else if( arr[i]==mx )
				cnt++;

		if( cnt>1 )
			cout<<"tie\n";
		else if(idx)
			cout<<idx+1<<"\n";
		else
			cout<<"chef\n";
	}
}