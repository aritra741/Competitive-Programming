#include <bits/stdc++.h>
using namespace std;

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
	return sqrt( (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) );
}

ld distsq( pt a, pt b )
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

ld f( pt a, pt b, pt p, ld t  )
{
	pt D = b - a;
	pt z = a + pt( D.x * t, D.y * t );
	
	return distsq( z, p );
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for ( int t = 1; t <= tc; t++ )
	{
		pt a, b, p, q;
		cin >> a.x >> a.y;
		cin >> b.x >> b.y;
		cin >> p.x >> p.y;
		cin >> q.x >> q.y;

		pt d1 = q - p;
		pt d2 = b - a;

		ld l = 0, r = 1;
		ld ans = 1e12;

		for ( int i = 0; i < 100; i++ )
		{
			ld m1 = l + (r - l) / 3;
			ld m2 = r - (r - l) / 3;
			ld f1 = f( p, q, pt( a.x + d2.x * m1, a.y + d2.y * m1 ), m1 );
			ld f2 = f( p, q, pt( a.x + d2.x * m2, a.y + d2.y * m2 ), m2 );

			if ( f1 < f2 )
				r = m2, ans = min(ans, f1);
			else
				l = m1, ans = min( ans, f2 );
		}

		cout <<"Case "<<t<<": "<< setprecision(10) <<fixed<< sqrt(ans) << "\n";
	}
}
