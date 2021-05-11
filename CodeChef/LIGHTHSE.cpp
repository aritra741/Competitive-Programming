#include <bits/stdc++.h>
#define pii pair<int,int>
#define piii pair<pii,int>
#define x first
#define y second
using namespace std;

bool cmp1( piii a, piii b ) // bottom left
{
	if ( a.x.x == b.x.x )
		return a.x.y < b.x.y;
	return a.x.x < b.x.x;
}

bool cmp2( piii a, piii b ) // top left
{
	if ( a.x.x == b.x.x )
		return a.x.y > b.x.y;
	return a.x.x < b.x.x;
}

bool cmp3( piii a, piii b ) // top right
{
	if ( a.x.x == b.x.x )
		return a.x.y > b.x.y;
	return a.x.x > b.x.x;
}

bool cmp4( piii a, piii b )	// bottom right
{
	if ( a.x.x == b.x.x )
		return a.x.y < b.x.y;
	return a.x.x > b.x.x;
}

bool chk( piii a, piii b, int tp )
{
	if (tp == 1)
	{
		if ( a.x.x <= b.x.x and a.x.y <= b.x.y )
			return 1;
		return 0;
	}
	if (tp == 2)
	{
		if ( a.x.x <= b.x.x and a.x.y >= b.x.y )
			return 1;
		return 0;
	}
	if (tp == 3)
	{
		// cout<<a.x.y<<" "<<b.x.y<<endl;
		if ( a.x.x >= b.x.x and a.x.y >= b.x.y )
			return 1;
		return 0;
	}
	else
	{
		if ( a.x.x >= b.x.x and a.x.y <= b.x.y )
			return 1;
		return 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--)
	{
		int n;
		cin >> n;

		piii arr[n + 5];
		bool done[n + 5];

		for ( int i = 0; i < n; i++ )
			cin >> arr[i].x.x >> arr[i].x.y, arr[i].y = i;

		std::vector<piii> v;

		sort( arr, arr + n, cmp1 );
		v.push_back(arr[0]);

		sort( arr, arr + n, cmp2 );
		for( int i=0;i<n;i++ )
		{
			bool f= 1;
			for( int j=0;j<v.size();j++ )
				if( arr[i].x.x==v[j].x.x and arr[i].x.y==v[j].x.y )
					f= 0;

			if(f)
			{
				v.push_back(arr[i]);
				break;
			}
		}

		sort( arr, arr + n, cmp3 );

		for( int i=0;i<n;i++ )
		{
			bool f= 1;
			for( int j=0;j<v.size();j++ )
				if( arr[i].x.x==v[j].x.x and arr[i].x.y==v[j].x.y )
					f= 0;

			if(f)
			{
				v.push_back(arr[i]);
				break;
			}
		}

		sort( arr, arr + n, cmp4 );
		
		for( int i=0;i<n;i++ )
		{
			bool f= 1;
			for( int j=0;j<v.size();j++ )
				if( arr[i].x.x==v[j].x.x and arr[i].x.y==v[j].x.y )
					f= 0;

			if(f)
			{
				v.push_back(arr[i]);
				break;
			}
		}

		std::vector<piii> ans;
		ans = v;

		for ( int mask = 1; mask < (1<<v.size()); mask++ )
		{
			memset( done, 0, sizeof(done) );

			for ( int i = 0; i < v.size(); i++ )
			{
				if (mask & (1 << i))
				{
					done[ v[i].y ] = 1;
					for ( int j = 0; j < n; j++ )
					{
						int tp = i + 1;

						if ( chk( v[i], arr[j], tp ) )
							done[ arr[j].y ] = 1;
					}
				}
			}

			// cout<<" "<<v[2].x.x<<" "<<v[2].x.y<<endl;

			int cnt = 0;

			for ( int i = 0; i < n; i++ )
				if (done[i])
					cnt++;

			// cout<<" "<<mask<<" "<<cnt<<endl;

			if (cnt == n and __builtin_popcount(mask) < ans.size())
			{
				ans.clear();

				for ( int i = 0; i < v.size(); i++ )
				{
					if (mask & (1 << i))
					{
						ans.push_back(v[i]);
					}
				}
			}
		}

		cout<<ans.size()<<"\n";

		for( auto p: ans )
		{
			cout<<p.y+1<<" ";

			if( p.x.x==v[0].x.x and p.x.y==v[0].x.y )
				cout<<"NE\n";
			else if( v.size()>1 and p.x.x==v[1].x.x and p.x.y==v[1].x.y )
				cout<<"SE\n";
			else if( v.size()>2 and p.x.x==v[2].x.x and p.x.y==v[2].x.y )
				cout<<"SW\n";
			else if( v.size()>3 and p.x.x==v[3].x.x and p.x.y==v[3].x.y )
				cout<<"NW\n";
		}
	}
}