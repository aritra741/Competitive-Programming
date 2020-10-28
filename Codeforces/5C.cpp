#include <bits/stdc++.h>
#define pii pair<char,int>
using namespace std;

bool match( char a, char b )
{
	if( a=='(' and b==')' )
		return 1;
	return 0;
}

int main()
{
	string s;
	cin>>s;

	stack<pii>st;
	map<int,int>mp;
	int curr= 0, ans= 0;

	for( int i=0;i<s.size();i++ )
	{
		if( !st.size() or ( st.size() and !match( st.top().first, s[i] ) ) )
			st.push(pii(s[i],i));
		else
		{
			int l= i, r= i-1, curr= i;
			while( st.size() and curr<s.size() and match(st.top().first,s[curr]) )
			{
				st.pop();
				curr++;
				l--;
				r++;
			}

			if(r>=i)
			{
				int last= -1;

				if( st.size() )
					last= st.top().second;

				int tot= r-last;

				mp[tot]++;

				ans= max(ans,tot);
				i= r;
			}
		}
	}	

	mp[0]= 1;

	cout<< ans <<" "<< mp[ans] <<"\n";
}