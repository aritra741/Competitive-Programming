#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int n,p;
	cin>>n>>p;

	int arr[n+5];

	for( int i=0;i<n;i++ )
		cin>>arr[i];

	sort( arr, arr+n );

	std::vector<int> ans;

	for( int x=1;x<=2000;x++ )
	{
		int val= 1;

		for( int i=0;i<n;i++ )
		{
			int notbigger= upper_bound( arr, arr+n, x+i )-arr;			
			notbigger-= i;

			if(notbigger<=0)
			{
				val= 0;
				break;
			}

			val= ( val*notbigger )%p;
		}

		if(val)
			ans.push_back(x);
	}

	cout<< ans.size() <<"\n";

	for( auto x: ans )
		cout<<x<<" ";
}