#include <bits/stdc++.h>
#define ll long long
using namespace std;

int tp;

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		ll x,y,s;
		cin>>x>>y>>s;

		ll ss= s;

		while(1)
		{
			if(ss==x)
			{
				tp= 0;
				break;
			}
			if(ss==y)
			{
				tp= 1;
				break;
			}
			
			ss/= 2;
		}

		
	}	
}