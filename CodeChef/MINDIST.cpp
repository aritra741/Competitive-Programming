#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pi acos(-1.0)
#define eps 1e-12
using namespace std;

ld a[100000 + 5], b[100000 + 5], c[100000 + 5], d[100000 + 5];
ld D[100000 + 5];
ld P[100000 + 5];
ld z[100000 + 5];
ld dotDC, dotDD;
int n;

ld dot( ld *a, ld *b )
{
	ld ans = 0;

	for ( int i = 0; i < n; i++ )
		ans += a[i] * b[i];

	return ans;
}

ld distsq( ll *A, ll *B )
{
	__int128 ans = 0;

	for ( int i = 0; i < n; i++ )
		ans += (A[i] - B[i]) * (A[i] - B[i]);

	return (ld)ans;
}

ld distsq( ld *A, ld *B )
{
	ld ans = 0;

	for ( int i = 0; i < n; i++ )
		ans += (A[i] - B[i]) * (A[i] - B[i]);

	return ans;
}

ld distsq( ld *A, ll *B )
{
	ld ans = 0;

	for ( int i = 0; i < n; i++ )
		ans += (A[i] - B[i]) * (A[i] - B[i]);

	return ans;
}

ld f( ld *A, ld *B, ld m  )
{
	for ( int i = 0; i < n; i++ )
		P[i] = a[i] + (b[i] - a[i]) * m;

	ld t = (( dot( D, P ) - dotDC )) / dotDD;

	for ( int i = 0; i < n; i++ )
		z[i] = A[i] + D[i] * t;

	// pt z = a + pt( D.x * t, D.y * t );
	ld ans;

	if ( fabs(t - 0.00) > eps and (t<0 or t>1) )
		ans = min( distsq( P, A ), distsq( P, B ) );
	else
		ans = distsq( z, P );

	return ans;
}

int main()
{
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);

	int tc;
	scanf("%d", &tc);

	while (tc--)
	{
		scanf("%d", &n);

		for ( int i = 0; i < n; i++ )
			scanf("%Lf", &a[i]);
		for ( int i = 0; i < n; i++ )
			scanf("%Lf", &b[i]);
		for ( int i = 0; i < n; i++ )
			scanf("%Lf", &c[i]);
		for ( int i = 0; i < n; i++ )
			scanf("%Lf", &d[i]);
		
		for ( int i = 0; i < n; i++ )
			D[i] = d[i] - c[i];

		ld l = 0.0, r = 1.0;
		ld ans = 1e30;

		dotDC= dot( D, c );
		dotDD= dot( D, D );

		while (r - l > eps)
		{
			ld m1 = l + (r - l) / 3.0;
			ld m2 = r - (r - l) / 3.0;
			ld f1 = f( c, d, m1 );
			ld f2 = f( c, d, m2 );

			if ( f1 < f2 and fabs(f1 - f2) > eps )
				r = m2, ans = f1;
			else if ( f1 > f2 and fabs(f1 - f2) > eps )
				l = m1, ans = f2;

			// cout << setprecision(12) << fixed << sqrt(f1) << " " << sqrt(f2) << " " << sqrt(ans) << endl;
		}

		printf("%.15Lf\n", sqrt(ans));
	}
}