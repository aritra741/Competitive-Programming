#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;

	getchar();
	while(tc--)
	{
		string s,t;
		getline(cin,s);
		getline(cin,t);

		int j= 0, cnt= 0;

		for( int i=0;i<s.size();i++ )
		{
			if( s[i]==t[j] )
			{
				j++;

				if( j==t.size() )
					cnt++, j= 0;
			}
		}

		cout<< (int)s.size()-cnt*t.size() <<"\n";
	}
}