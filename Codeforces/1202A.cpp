#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		string s,t;
		cin>>t>>s;

		reverse( s.begin(), s.end() );
		reverse( t.begin(), t.end() );
		
		int ft= 1e9, lt= 1e9, ls= 1e9, fs= 1e9;

		while(s.size()<t.size())
			s.push_back('0');
		while(s.size()>t.size())
			t.push_back('0');
		std::vector<int> v;

		for( int i=0;i<t.size();i++ )
			if( t[i]=='1' )
				v.push_back(i);

		int k= s.size()+1;
		for( int i=0;i<s.size();i++ )
		{
			if( s[i]=='0' )
				continue;
			int pos= lower_bound( v.begin(), v.end(), i )-v.begin();

			if( pos<v.size() )
				k= v[pos]-i;
			break;
		}

		if(k>s.size())
			k= 0;

		cout<<k<<"\n";
	}
}