#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin>>tc;

	while(tc--)
	{
		int n;
		cin>>n;

		n*= 4;
		n--;

		map<int,int>mpx, mpy;
		int p,q;

		for( int i=0;i<n;i++ )
			cin>>p>>q, mpx[p]++, mpy[q]++;

		int ansx, ansy;

		for( auto x: mpx )
			if( x.second&1 )
				ansx= x.first;

		for( auto y: mpy )
			if( y.second&1 )
				ansy= y.first;

		cout<< ansx <<" "<< ansy <<"\n";
	}
}