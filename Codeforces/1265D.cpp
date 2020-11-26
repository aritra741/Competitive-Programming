#include <bits/stdc++.h>
using namespace std;

bool eka(int a,int b,int c, int d)
{
	if( a>1 and !(b+c+d) )
		return 1;
	if( b>1 and !(a+c+d) )
		return 1;
	if( c>1 and !(b+a+d) )
		return 1;
	if( d>1 and !(b+c+a) )
		return 1;
	return 0;
}

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if( eka(a,b,c,d) )
		return cout<<"NO\n", 0;

	deque<int> v;

	if ( d > c )
	{
		if ( a or b or d > c + 1 )
			return cout << "NO\n", 0;

		int x = 1;

		while (1)
		{
			if ( x & 1 )
			{
				if (!d)
					break;

				d--, v.push_back(3), x ^= 1;
			}
			else
			{
				if (!c)
					break;

				c--, v.push_back(2), x ^= 1;
			}
		}

		cout << "YES\n";

		for ( auto xx : v )
			cout << xx << " ";

		return 0;
	}

	while (d--)
		v.push_back(3), v.push_back(2), c--;

	if ( c and b and c - 1 >= b and a )
		return cout << "NO\n", 0;

	else if (!c and !b and v.size() and a)
		return cout << "NO\n", 0;

	while (c > 1 and b)
		v.push_back(1), v.push_back(2), b--, c--;
	if(b and b>=a)
		v.push_back(1), b--;

	bool agey = 0;

	if ( a > b + 1 )
		return cout << "NO\n", 0;

	if ( b > a + 1 )
		return cout << "NO\n", 0;

	if ( b == a + 1 and !c )
		return cout << "NO\n", 0;

	if ( b == a + 1 and c )
		v.push_back(2), v.push_back(1), c--, b--;

	else if ( c )
		agey = 1;

	int x = 1;

	while (1)
	{
		if ( x & 1 )
		{
			if (!a)
				break;

			a--, v.push_back(0), x ^= 1;
		}
		else
		{
			if(!b)
				break;

			b--, v.push_back(1), x ^= 1;
		}
	}

	if (agey)
		v.push_front(2), c--;

	if( a>0 or b>0 or c>0 or d>0 )
		return cout<<"NO\n", 0;

	for( int i=1;i<v.size();i++ )
		if( abs(v[i]-v[i-1])!=1 )
			return cout<<"NO\n", 0;

	cout << "YES\n";

	for ( auto xx : v )
		cout << xx << " ";
}
