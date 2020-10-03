#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll fl( ll x )
{
	if(x<0)
		return x/2;
	return (x+1)/2;
}

ll diff[100007];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin>>n;

	ll arr[n+5];

	for( ll i=0;i<n;i++ )
		cin>>arr[i];

	ll k= 0;

	for( ll i=1;i<n;i++ )
		k+= max( 0LL, arr[i]-arr[i-1] ), diff[i]= arr[i]-arr[i-1];

	cout<< max( fl(arr[0]+k), arr[0]+k-fl(arr[0]+k) ) <<"\n";

	ll q;
	cin>>q;

	while(q--)
	{
		ll l,r,x;
		cin>>l>>r>>x;

		l--, r--;

		if(l-1>=0)
			k-= max(0LL,diff[l]), diff[l]+= x, k+= max(0LL,diff[l]);
		if( r+1<n )
			k-= max(0LL,diff[r+1]), diff[r+1]-= x, k+= max(0LL,diff[r+1]);

		if(!l)
			arr[0]+= x;

		cout<< max( fl(arr[0]+k), arr[0]+k-fl(arr[0]+k) ) <<"\n";
	}
}