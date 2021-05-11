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

		int x, ans= 0;
		int arr[n+5];

		for( int i=0;i<n;i++ )
			cin>>arr[i];

		bool f= 0;

		for( int i=0;i<n;i++ )
		{
			set<int>st;
			st.insert(arr[i]);

			int x= 0;

			for( int j=0;j<n;j++ )
			{
				if( arr[j]!=arr[i] )
					x^= arr[j];
				else if( j and arr[j-1]!=arr[i] )
					st.insert(x), x= 0;
			}

			cout<<st.size()<<endl;

			if(arr[n-1]!=arr[i])
				st.insert(x);

			cout<<" "<<st.size()<<endl;
			if(st.size()==1)
				f= 1;
		}

		if(f)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
} 