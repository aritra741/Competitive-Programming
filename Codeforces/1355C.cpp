#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll sum( ll x )
{
	return (x*(x+1))/2;
}

int arr[500007];

int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;

	int n= b-a+1;

	for( int i=a;i<=b;i++ )
		arr[i-a]= i;

	ll ans= 0;

	for( int y=b;y<=c;y++ )
	{
		int baki= c-y;

		int pos= upper_bound( arr, arr+n, baki )-arr;
		ll niteparbo= n-pos;
		if(!niteparbo)
			continue;
		ll ase= d-c+1;
		ll cross= max(0,min(y+arr[pos]-c, d-c+1));
		ll shesh= max(0LL,niteparbo-1-(d-c+1-cross));
		ans+= cross*niteparbo+sum(niteparbo-1)-sum(shesh);
	}

	cout<< ans <<"\n";
}