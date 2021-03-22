#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll sum= 0;

	for( int i=2;i<=20;i++ )
	{
		sum+= i*((1LL<<(i-1))-1);
		ll baad= 0;

		for( int j=1;j<i;j++ )
			baad+= ((1LL<<(i-j))-1)*j;

		cout<<i<<" "<< sum-baad <<endl;
	}
}