#include <bits/stdc++.h>
#define ll long long
#define mx 100007 
#define m 1000000007
using namespace std;

int cnt[mx];
bool arr[mx];
int sign[mx];
int hit[mx];
 
void init()
{
    for( int i=0;i<mx;i++ )
        sign[i]= 1;
 
    for( ll i=2; i<mx; i++ )
    {
        if(!arr[i])
        {
            hit[i]++;
            for( ll j=i*2; j<mx; j+=i )
            {
                arr[j]= 1;
                hit[j]++;
                ll pp= j;
 
                pp/= i;
 
                if(pp%i==0)
                    sign[j]= 0;
            }
        }
    }
 
    for( ll i=2;i<mx;i++ )
    {
        if(!sign[i])
            continue;
        if(hit[i]&1)
            sign[i]= -1;
    }
}

ll Pow( ll x, ll y )
{
	ll res= 1;

	while(y>0)
	{
		if(y&1)
			res= (res*x)%m;
		x= (x*x)%m;
		y>>= 1;
	}

	return res;
}

int main()
{
	init();
	int n;
	cin>>n;

	int arr[n+5];

	for( int i=1;i<=n;i++ )
	{
		cin>>arr[i];
		ll p= arr[i];

		for( ll x=1;x*x<=p;x++ )
		{
			if(p%x==0)
			{
				cnt[x]++;
				if(x!=p/x)
					cnt[p/x]++;
			}
		}
	}

	ll baad= 0;

	for( int i=2;i<mx;i++ )
		if(cnt[i])
			baad+= ((Pow(2,cnt[i])-1)*sign[i]+m)%m;

	ll ans= (Pow(2,n)-1+baad+m)%m;

	cout<< ans <<"\n";
}