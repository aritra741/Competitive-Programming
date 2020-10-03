#include <bits/stdc++.h>
#define mx 320
#define ll long long
using namespace std;

std::vector<int> v;
bool ok[mx];

void sieve()
{
	for( ll i=2;i<mx;i++ )
	{
		if(ok[i])
			continue;
		v.push_back( i );
		for( ll j=i*2;j<mx;j+=i )
			ok[j]= 1;
	}
}

int main()
{
	sieve();

	cout<<v.size()<<endl;
}