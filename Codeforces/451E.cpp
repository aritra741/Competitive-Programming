#include <iostream>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define mod 1000000007
#define mx 1000000
#define ll long long
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

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

int main()
{
	fast;

	ll n,s;
	cin>>n>>s;

	__int128 arr[n+5];

	for( int i=0;i<n;i++ )
		cin>>arr[i];

	ll ans= 1;

	for( ll i=s+1;i<=s+n-1;i++ )
		ans= ( ans*i )%mod;

	for( int i=2;i<=n-1;i++ )
		ans= ( ans*Pow( i, mod-2 ) )%mod;

	for( int mask=1;mask<(1<<n);mask++ )
	{
		ll numer= 1;
		ll ss= s;
		int k= __builtin_popcount(mask);

		for( int j=0;j<n;j++ )
		{
			if( mask&(1<<j) )
				ss-= arr[j];
		}

		for( ll j=ss+1;j<=ss+n-1;j++ )
			numer= ( numer*j )%mod;

		for( int j=2;j<=n-1;j++ )
			numer= (numer*Pow(j, mod-2))%mod;


		if(k&1)
			ans= ( ans-numer )%mod, ans= ( ans+mod )%mod;
		else
			ans= ( ans+numer )%mod;

		cout<<mask<<" "<<ans<<endl;
	}

	cout<< ans;
}