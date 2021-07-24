#include <bits/stdc++.h>
#define mx 200007
#define mod 1000000007
#define ll long long
using namespace std;

ll f[mx+7], inv[mx+7];

ll Pow( ll x, ll y )
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

void init()
{
	f[0]= f[1]= inv[0]= inv[1]= 1;

	for( int i=2;i<=mx;i++ )
		f[i]= (f[i-1]*i)%mod;
	inv[mx]= Pow( f[mx], mod-2 );
	for( int i=mx-1;i>1;i-- )
		inv[i]= ( inv[i+1]*(i+1) )%mod;
}

ll ncr( ll n, ll r )
{
	ll up= f[n];
	ll down= (inv[r]*inv[n-r])%mod;

	return (up*down)%mod;
}

int main()
{
	init();

	int h,w,a,b;
	cin>>h>>w>>a>>b;

	ll tot= ncr(h+w-2,h-1);
	ll last= 0;
	cout<<" "<<tot<<endl;
	for( int i=b+1;i<=w;i++ )
	{
		ll ways= (ncr( i+h-a-2, i-1 )*(ncr( a+w-i-2, a-1 )))%mod;
		
	}

	cout<< tot;
}