#include <bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;

struct pt{
	double x,y;
	pt(){}
	pt( double _x, double _y ){ x= _x, y= _y; }
};

double dot( pt a, pt b )
{
	return a.x*b.x+a.y*b.y;
}

double val( pt p )
{
	return sqrt( p.x*p.x+p.y*p.y );
}

int main()
{
	// freopen( "angle2.in", "r", stdin );
	// freopen( "angle2.out", "w", stdout );
	
	pt p,q;
	cin>>p.x>>p.y;
	cin>>q.x>>q.y;
	
	double dotp= dot( q, p );
	double cos= dotp/( val(p)*val(q) );
	double ang= acos(cos);

	cout<<setprecision(10)<<fixed<< ang <<"\n";
}