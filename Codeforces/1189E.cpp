#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll Pow( ll x, ll y, ll mod )
{
 	ll res= 1%mod;

 	while(y>0)
 	{
 		if(y&1)
 			res= (res*x)%mod;
 		x= (x*x)%mod;
 		y>>= 1;
 	}

 	return res;	
}

int main()
{
	ll n,p,k;
	cin>>n>>p>>k;

	ll arr[n+5];
	map<ll,ll>mp;
	ll ans= 0;

	for( int i=0;i<n;i++ )
	{
		cin>>arr[i];

		ans+= mp[ (Pow( arr[i], 4, p )-(arr[i]*k)%p+p)%p ];
		mp[ (Pow( arr[i], 4, p )-(arr[i]*k)%p+p)%p ]++;
	}
 
	cout<< ans <<"\n";

}