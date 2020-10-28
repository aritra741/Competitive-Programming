#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		ll p,f;
		cin>>p>>f;

		ll cnts, cntw;
		cin>>cnts>>cntw;

		ll s,w;
		cin>>s>>w;

		ll ans= 0;

		for( ll swordnibo=0;swordnibo<=cnts;swordnibo++ )
		{
			ll weighttaken= swordnibo*s;

			if(weighttaken>p)
				break;

			ll baki= p-weighttaken;
			ll tot= swordnibo+min(baki/w,cntw);
			ll swordbaki= cnts-swordnibo;
			ll axebaki= cntw-min(baki/w,cntw);
			ll onibe;
			ll ff= f;

			if( s<=w )
			{
				onibe= min(ff/s, swordbaki);
				ff-= onibe*s;
				onibe+= min( ff/w, axebaki );
			}
			else
			{
				onibe= min(ff/w, axebaki);
				ff-= onibe*w;
				onibe+= min( ff/s, swordbaki );
			}

			ans= max( ans, tot+onibe );
		}

		cout<< ans <<"\n";
	}
}