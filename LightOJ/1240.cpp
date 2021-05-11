#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
#define ld long double
#define pi acos(-1.0)
#define eps 1e-7
using namespace std;

struct pt {
	ld x, y, z;
	pt() {}
	pt( ld _x, ld _y, ld _z ) { x = _x, y = _y, z = _z;  }


	pt operator- ( pt p ) const
	{
		return pt( x - p.x, y - p.y, z - p.z );
	}
	pt operator+ ( pt p ) const
	{
		return pt( x + p.x, y + p.y, z + p.z );
	}
};


ld dot( pt a, pt b )
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

ld val( pt p )
{
	return sqrt( p.x * p.x + p.y * p.y + p.z * p.z );
}

ld angle( pt p, pt q )
{
	ld dotp = dot( q, p );
	ld cos = dotp / ( val(p) * val(q) );
	ld ang = acos(cos);

	return ang;
}

ld distsq( pt a, pt b )
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
}

ld f( pt a, pt b, pt p )
{
	pt D = b - a;
	ld t= ( dot( D, p )-dot( D,a ) )/dot( D, D );
	pt z= a+pt( D.x*t, D.y*t, D.z*t );

	ld ans;

	if( fabs(t-0.00)>eps and (t<0 or t>1 ) )
		ans= min( distsq( a, p ), distsq( b, p ) );
	else 
		ans= distsq( z, p );

	return ans; 
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for ( int t = 1; t <= tc; t++ )
	{
		pt a, p, q;
		cin >> p.x >> p.y>>p.z;
		cin >> q.x >> q.y>>q.z;
		cin >> a.x >> a.y>>a.z;

		pt d1 = q - p;

		ld l = 0, r = 1;
		ld ans = 1e12;

		cout << "Case " << t << ": " << setprecision(10) << fixed << sqrt(f(p,q,a)) << "\n";
	}
}