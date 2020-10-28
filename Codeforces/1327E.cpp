#include <bits/stdc++.h>
#define mx 200007
#define mod 998244353
#define ll long long
using namespace std;

ll f[mx], inv[mx];
ll p[mx], sum[mx];
ll ans[mx];

void init()
{
	p[0]= 1;
	for( int i=1;i<mx;i++ )
		p[i]= ( p[i-1]*10 )%mod;
}


int main()
{
	init();

	int n;
	cin>>n;

	for( int i=1;i<n;i++ )
	{
		int range= n-2;
		int poss= range-i+1;
		
		ll tot= 0;

		if( poss>0 )
		{
			tot= poss;
			tot= ( tot*81 )%mod;
			tot= ( tot*10 )%mod;

			int baki= n-i-2;

			if(baki>0)
				tot= ( tot*p[baki] )%mod;
		}

		ll ekdik= ( p[n-i-1]*9*2*10 )%mod;

		tot= ( tot+ekdik )%mod;

		cout<<tot<<" ";
	}

	cout<<"10\n";
}