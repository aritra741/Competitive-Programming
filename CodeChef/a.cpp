#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main()
{
	fast;

	int tc;	
	cin>>tc;

	while(tc--)
	{
		ll n,k;
		cin>>n>>k;

		ll ans= 0;
		ll dv= k/n;
		ll baad= k%n;
		ll tot= n-baad;
		ans+= tot*dv*dv;
		ans+= baad*(dv+1)*(dv+1);

		cout<< ans <<"\n";
	}
}
