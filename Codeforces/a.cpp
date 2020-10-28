#include <bits/stdc++.h>
using namespace std;

map<int,int>mp;

void rec( vector<int> v, int i )
{
	if(i>=17)
	{
		int pp= -1, xx= 0, px= -1;
		for( auto x: v )
		{
			if(x<=pp)
				return;
			xx^= x;
			if(xx<=px)
				return;
			px= xx;
			pp= x;
		}

		for( auto x: v )
			cout<<x<<" ";
		cout<<endl;

		return;
	}

	v.push_back( i );
	rec( v, i+1 );
	v.pop_back();
	rec( v, i+1 );
}

int main()
{
	std::vector<int> v;
	rec( v, 1 );

}