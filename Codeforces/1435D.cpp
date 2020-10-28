#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	set<int>st;
	int last= 2e9;
	std::vector<int> pos(n+1), ans(n+1);
	map<int,int>mp;
	int cnt1= 0;

	for( int i=1;i<=2*n;i++ )
	{
		char c;
		cin>>c;

		if(c=='+')
			st.insert(i), mp[i]= cnt1++, last= 0;
		else
		{
			int x;
			cin>>x;

			if( !st.size() or x<last )
				return cout<<"NO\n", 0;
			
			pos[x]= i;
			last= x;
		}
	}	

	for( int i=1;i<=n;i++ )
	{
		auto pp= st.lower_bound( pos[i] );

		if( pp==st.begin() )
			return cout<<"NO", 0;

		pp--;

		if( i+1<=n and pos[i+1]<pos[i] and pos[i+1]>(*pp) )
			return cout<<"NO\n", 0;

		ans[mp[*pp]]= i;
		st.erase(pp);
	}

	cout<<"YES\n";

	for( int i=0;i<n;i++ )
		cout<< ans[i] <<" ";
}