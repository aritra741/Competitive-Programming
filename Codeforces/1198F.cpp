#include <bits/stdc++.h>
#define ll long long
#define mx 1000007
using namespace std;

int val[20];
map<int,int>mp;
bool f[mx];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for ( int i = 1; i <= n; i++ )
		cin >> arr[i];

	std::vector<int> v;
	int pos= 0;

	int x= arr[1];

	for( int i=2;i*i<=arr[1];i++ )
	{
		if(x%i)
			continue;

		v.push_back(i);
		mp[i]= pos++;

		while(x%i==0)
			x/= i;
	}

	if(x>1)
		v.push_back(x), mp[x]= pos++;

	for( int i=2;i<=n;i++ )
	{
		bool ff= 1;
		for( auto y: v )
		{
			if(arr[i]%y)
			{
				ff= 0;
				if(!val[mp[y]])
					val[mp[y]]= i;
			}
		}

		if(ff)
			f[i]= 1;
	}

	for( int i=0;i<pos;i++ )
		if( !val[i] )
			return cout<<"NO\n", 0;

	cout<<"YES\n";

	for( int i=1;i<=n;i++ )
	{
		if(f[i])
			cout<<"1 ";
		else
			cout<<"2 "; 
	}
}