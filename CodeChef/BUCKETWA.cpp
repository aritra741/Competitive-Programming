#include <bits/stdc++.h>
using namespace std;

long double lim= 1e7;
long double dh, dl, dr, k;

long double f( long double x )
{
	return sqrt( x*x+dh*dh )/lim+sqrt( (dr-x)*(dr-x)+dl*dl )/(lim/k);
}

long double f2( long double x )
{
	return sqrt( x*x+dh*dh )+sqrt( (dr-x)*(dr-x)+dl*dl );
}

long double ternary_search(long double l, long double r) {
	long double eps = 1e-11;              
	for( int i=0;i<=1000;i++ ) {
		long double m1 = (l * 2 + r) / 3.0;
		long double m2 = (l + 2 * r) / 3.0;
		long double f1 = f(m1);      
		long double f2 = f(m2);      
		cout<<m1<<" "<<f1<<" "<<m2<<" "<<f2<<endl;
		if (f1 < f2)
			r = m1;
		else
			l = m2;
	}
	return f2(l);                    
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> dh >> dl >> dr >> k)
	{
		if( !(dh+dl+dr+k) )
			break;

		long double dist= ternary_search( 0, dr );

		cout<<setprecision(10)<<fixed<< dist <<"\n";
	}

}