#include <bits/stdc++.h>
#define ld long double
#define pi acos(-1.0)
#define eps 1e-7
using namespace std;

struct pt {
	ld x, y;
	pt() {}
	pt( ld _x, ld _y ) { x = _x, y = _y; }


	pt operator- ( pt p ) const
	{
		return pt( x - p.x, y - p.y );
	}
	pt operator+ ( pt p ) const
	{
		return pt( x + p.x, y + p.y );
	}
};


ld dot( pt a, pt b )
{
	return a.x * b.x + a.y * b.y;
}

ld cross( pt a, pt b )
{
	return a.x * b.y - a.y * b.x;
}

ld val( pt p )
{
	return sqrt( p.x * p.x + p.y * p.y );
}

ld angle( pt p, pt q )
{
	ld dotp = dot( q, p );
	ld cos = dotp / ( val(p) * val(q) );
	ld ang = acos(cos);

	return ang;
}

pt RotateCCW(pt p, ld t)
{
	return pt(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));
}

ld dist( pt a, pt b )
{
	return sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) );
}

int main()
{
	freopen( "distance1.in", "r", stdin );
	freopen( "distance1.out", "w", stdout );

	ld A,B,C;
	pt p;

	cin>>p.x>>p.y;
	cin>>A>>B>>C;

	pt a,b;

	if( fabs(A-0)<=eps )
	{
		a= pt(1,-(C/B)), b= pt(2,-(C/B));
	}
	else if( fabs(B-0)<=eps )
	{
		a= pt(-(C/A),1), b= pt(-(C/A),2);	
	}
	else
	{
		a.x= -(C/A);
		a.y= 0;
		b.x= -((C+1*B)/A);
		b.y= 1;
	}

	pt D= b-a;
	ld t= ( dot( D, p )-dot( D,a ) )/dot( D, D );

	pt z= a+pt( D.x*t, D.y*t );

	cout<<setprecision(10)<<fixed<< dist( z, p ) <<"\n";
}