#include <bits/stdc++.h>
using namespace std;

multiset<int>bob, alice, both;

int main()
{
	int n, k;
	cin >> n >> k;

	for ( int i = 0; i < n; i++ )
	{
		int t, a, b;
		cin >> t >> a >> b;

		if (a and b)
			both.insert(t);
		else if (a)
			alice.insert(t);
		else if (b)
			bob.insert(t);
	}

	int ans= 0;
	int a = 0, b = 0;

	while (a < k and b < k)
	{
		if ( both.empty() or alice.empty() or bob.empty() )
			break;

		if ( alice.size() and bob.size() )
		{
			int aval = *(alice.begin());
			int bval = *(bob.begin());

			if ( both.size() )
			{
				int bbval = *(both.begin());

				if ( aval + bval < bbval )
				{
					a++,b++;
					ans+= aval+bval;
					alice.erase( alice.find(aval) );
					bob.erase( bob.find(bval) );
				}
				else
				{
					a++,b++;
					ans+= bbval;
					both.erase( both.find(bbval) );
				}
			}
			else
			{
				a++, b++;
				ans+= aval+bval;
				alice.erase( alice.find(aval) );
				bob.erase( bob.find(bval) );
			}
		}
	}

	if(a<k)
	{
		if( b<k or !alice.size() )
		{
			std::vector<int> v;
			for( auto x: both )
			{
				if(a==k)
					break;
				a++,b++;
				ans+= x;
				v.push_back(x);
			}

			for( auto x: v )
			{
				both.erase( both.find(x) );
			}
		}
		
		if( a<k and alice.size() )
		{
			std::vector<int> v;

			for( auto x: alice )
			{
				if(a==k)
					break;
				v.push_back(x);
				ans+= x;
				a++;
			}

			for( auto x: v )
				alice.erase( alice.find(x) );
		}
	}

	if(b<k)
	{
		if( a<k or !bob.size() )
		{
			std::vector<int> v;
			for( auto x: both )
			{
				if(b==k)
					break;
				a++,b++;
				ans+= x;
				v.push_back(x);
			}

			for( auto x: v )
			{
				both.erase( both.find(x) );
			}
		}

		if( b<k and bob.size() )
		{
			std::vector<int> v;

			for( auto x: bob )
			{
				if(b==k)
					break;
				v.push_back(x);
				ans+= x;
				b++;
			}

			for( auto x: v )
				bob.erase( bob.find(x) );
		}
	}

	if( a<k or b<k )
	{
		if( both.size() )
		{
			for( auto x: both )
			{
				if(a>=k and b>=k)
					break;
				a++,b++;
				ans+= x;
			}
		}

	}

	if( a<k or b<k )
		return cout<<"-1\n", 0;

	cout<< ans <<"\n";
}
