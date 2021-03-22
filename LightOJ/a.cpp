#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		int n,k;
		cin>>n>>k;

		string s;
		cin>>s;

		int cnt= 0;

		for( int i=0;i<k;i++ )
			if( s[i]==s[n-i-1] )
				cnt++;
			else
				break;

		if(cnt==k and cnt*2<n)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}