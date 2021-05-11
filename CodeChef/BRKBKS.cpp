#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		int s;
		cin>>s;

		int a,b,c;
		cin>>a>>b>>c;

		if( s==1 )
			cout<<"3\n";
		else
		{
			int tot= a+b+c;

			if(s>=tot)
				cout<<"1\n";
			else
			{
				if( a+b<=s or b+c<=s )
					cout<<"2\n";
				else
					cout<<"3\n";
			}
		}
	}
}