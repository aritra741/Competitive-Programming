#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

map<pii,int>mp;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin>>s;

	mp[pii(0,0)]++;

	int a= 0, b= 0, c= 0;
	ll ans= 0;

	for( auto x: s )
	{
		if(x=='A')
			a++;
		if(x=='B')
			b++;
		if(x=='C')
			c++;
		
		ans+= mp[pii(a-b,a-c)];
		mp[pii(a-b,a-c)]++;
	}

	cout<< ans;
}