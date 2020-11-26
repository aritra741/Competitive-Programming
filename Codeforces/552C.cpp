// https://codeforces.com/blog/entry/18696?#comment-236555

#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool Find( ll w, ll m );

bool check( ll w, ll m )
{
	return( w<=2 or m==1 or Find(w,m) or Find( w, m-1 ) or Find(w,m+1) );
}

bool Find( ll w, ll m )
{
	if( m%w )
		return 0;
	return check( w, m/w );
}

int main()
{
	ll m,w;
	cin>>w>>m;

	if( check(w,m) )
		cout<<"YES\n";
	else
		cout<<"NO\n";
}