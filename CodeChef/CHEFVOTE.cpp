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

		int arr[n+5], ans[n+5];
		int tot= 0;
		set<int>st;

		for( int i=0;i<n;i++ )
			cin>>arr[i], tot+= arr[i], st.insert(i);

		if(tot!=n)
		{
			cout<<"-1\n";
			continue;
		}

		bool f= 1;

		for( int i=n-1;i>=0;i-- )
		{
			for( int j=0;j<arr[i];j++ )
			{
				int v= -1;
				for( auto x: st )
				{
					if( x!=i )
					{
						ans[x]= i;
						v= x;
						break;
					}
				}

				if(v>-1)
					st.erase(v);
				else
				{
					f= 0;
					break;
				}
			}
		}	

		if(!f)
		{
			cout<<"-1\n";
			continue;
		}

		for( int i=0;i<n;i++ )
			cout<<ans[i]+1<<" ";

		cout<<"\n";
	}
}