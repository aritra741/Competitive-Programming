#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

std::vector<int> v;
map<int,int>mp;

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

ll rec( ll val )
{
	if(mp.find(val)!=mp.end())
		return mp[val];

	ll tot= Pow( 2, val-1 );

	ll vv= val;

	for( int i=0;i<v.size() and 1LL*v[i]*v[i]<=vv;i++ )
	{
		if(vv%v[i])
			continue;
		if(vv<v[i])
			break;

		tot= (( tot-rec(vv/v[i]) )%mod+mod)%mod;

		if(v[i]!=(vv/v[i]))
			tot= (( tot-rec(v[i]) )%mod+mod)%mod;			
	}

	if(val>1)
		tot= (( tot-rec(1) )%mod+mod)%mod;

	return mp[val]= tot;
}

int main()
{
	ll x,y;
	cin>>x>>y;

	if(y%x)
		return cout<<"0", 0;

	for( int i=2;i*i<=y;i++ )
	{
		if(y%i)
			continue;
		v.push_back(i);

		if(i!=y/i)
			v.push_back(y/i);
	}

	if(y>1)
		v.push_back(y);

	sort( v.begin(), v.end() );

	cout<< rec(y/x) <<"\n";
}