#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll Pow( ll x, ll y, ll mod )
{
	ll res= 1;

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
	ll a,b,p,x;
	cin>>a>>b>>p>>x;

	ll ans= 0; 

	for( ll j=0;j<p-1 and j<=x;j++ )
	{
		ll niche= Pow(a,j,p);
		ll i= (j-(b*Pow(niche,p-2,p))%p+p)%p;
		ll mx= (x-j)/(p-1);
		if(i<=mx)
			ans+= ((mx-i)/p)+1;
	}

	cout<< ans <<"\n";
}