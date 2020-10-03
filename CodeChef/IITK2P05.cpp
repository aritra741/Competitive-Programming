#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll sq( ll n )
{
	ll x= sqrt(n);
	for( ll i=max(0LL,x-3);i<=min(n,x+3);i++ )
		if( i*i==n )
			return i;

	return 0;
}

__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

bool cmp(__int128 x, __int128 y) { return x > y; }

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		ll n,m;
		cin>>n>>m;

		std::vector<ll> v;

		for( ll i=2;i<=min(n,1000000LL);i++ )
		{
			if(n%i)
				continue;

			ll x= 1;

			while(n%i==0)
				v.push_back(i), n/= i, x*= i;

			ll y= x/i;

			m/= (x-y);
		}

		if(n>1)
		{
			if(m==n-1)
				v.push_back(n);
			else
			{
				if(sq(n))
					v.push_back(sq(n)), v.push_back(sq(n));
				else
				{
					long double aplusb= n-m+1+1e-9;
					long double aplusbsq= aplusb*aplusb;
					long double aminusbsq= aplusbsq-4*n;
					ll aminusb= sqrt(aminusbsq)+1e-9;

					ll a= (aplusb+aminusb)/2;

					v.push_back(a);
					v.push_back(n/a);
				}
			}
		}
		
		sort( v.begin(), v.end() );

		for( auto x: v )
			cout<<x<<" ";

		cout<<"\n";

		__int128 x= 9, y= 5;

		print(x+y);
	}
}