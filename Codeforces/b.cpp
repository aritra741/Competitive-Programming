#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;

	for( int t=1;t<=tc;t++ )
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;

		int tot= a+min(b,c);

		cout<<"Case #"<<t<<": ";

		if(tot&1)
			cout<<"Rabbit\n";
		else
			cout<<"Horse\n";
	}
}