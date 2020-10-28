#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		int n,m;
		cin>>n>>m;

		set<string>st;

		for( int i=0;i<n;i++ )
		{
			string s;
			cin>>s;

			st.insert(s);
		}

		ll target= ((1LL<<m)-n+1)/2;
		// cout<<target<<endl; 
		string ans;

		for( int i=0;i<m;i++ )
		{
			ll zeroboshaleways= 1LL<<(m-i-1);
			ll cnt= 0;

			std::vector<string> v;

			for( auto s: st )
			{
				bool f= 1;
				for( int j=0;j<i;j++ )
				{
					if( s[j]!=ans[j] )
					{
						f= 0;
						break;
					}
				}

				if(f)
					v.push_back(s);
			}
			
			for( auto s: v )
				if( s[i]=='0' )
					cnt++;  

			zeroboshaleways-= cnt;
			// cout<<i<<" "<<zeroboshaleways<<" "<<target<<endl;	
			if(zeroboshaleways>=target)
				ans.push_back('0');
			else
				ans.push_back('1'), target-= zeroboshaleways;
		}

		cout<< ans <<"\n";
	}
}