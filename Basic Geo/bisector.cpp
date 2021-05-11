#include <bits/stdc++.h>
#define ld long double
#define pi acos(-1.0)
using namespace std;

struct pt {
	ld x, y;
	pt() {}
	pt( ld _x, ld _y ) { x = _x, y = _y; }


	pt operator- ( pt p ) const
	{
		return pt( x - p.x, y - p.y );
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

int main()
{
	freopen( "bisector.in", "r", stdin );
	freopen( "bisector.out", "w", stdout );

	pt p, q, r;

	cin >> p.x >> p.y;
	cin >> q.x >> q.y;
	cin >> r.x >> r.y;

	pt pr = r - p;
	pt pq = q - p;

	ld ang = angle( pr, pq );
	pt bis;

	if ( fabs(0.00 - ang) > 1e-7 )
	{
		if ( cross( pr, pq ) >= 0 )
			bis = RotateCCW( pr, ang / 2.0 );
		else
			bis = RotateCCW( pq, ang / 2.0 );
	}
	else
		bis.x= q.x, bis.y= q.y;

	// cout<<bis.x<<" "<<bis.y<<endl;

	pt secondPoint;
	secondPoint.x = p.x+bis.x;
	secondPoint.y = p.y+bis.y;

	ld A = p.y - secondPoint.y;
	ld B = secondPoint.x - p.x;
	ld C = -p.y * (secondPoint.x - p.x) + p.x * ( secondPoint.y - p.y );

	if( fabs(A-0.00)<1e-7 )
		A= 0;
	if( fabs(B-0.00)<1e-7 )
		B= 0;
	if( fabs(C-0.00)<1e-7 )
		C= 0;
	

	cout << setprecision(10) << fixed << A << " " << B << " " << C << "\n";
}