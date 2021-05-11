#include <bits/stdc++.h>
#define eps 1e-7
#define ll long long
using namespace std;

struct point
{
	ll x, y;
} base;

vector<point> ret(200007), p;
std::vector<point> hh;

int sign( point p, point q, point r )
{
	ll val = (q.y - p.y) * (r.x - q.x) -
	         (q.x - p.x) * (r.y - q.y);

	val = -val;

	if (val < 0)
		return 1;
	if (val > 0)
		return 2;
	return 0;
}

ll dist( point a, point b )
{
	return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool cmp( point a, point b )
{
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

void bord()
{
	int k = 0, n = p.size();
	sort(p.begin(), p.end(), cmp);

	for (int i = 0; i < n; i++)
	{
		while (k >= 2 and sign(ret[k - 2], ret[k - 1], p[i]) != 2)
			k--;
		ret[k++] = p[i];
	}
	int t = k;
	for (int i = n - 2; i >= 0; i--)
	{
		while (k > t and sign( ret[k - 2], ret[k - 1], p[i] ) != 2)
			k--;
		ret[k++] = p[i];
	}

	ret.resize(k - 1);
	hh = ret;
}

bool inside( point a )
{
	int n = ret.size();
	int low = 1, high = n - 1;

	while (high - low > 1)
	{
		int mid = (low + high) / 2;
		if ( sign( ret[0], ret[mid], a ) == 1 )
			high = mid;
		else
			low = mid;
	}

	int val1 = sign( ret[0], ret[low], a );
	int val2 = sign( ret[low], ret[high], a );
	int val3 = sign( ret[high], ret[0], a );

	if (val1 == 1)
		val1 = -1;
	if (val2 == 1)
		val2 = -1;
	if (val3 == 1)
		val3 = -1;

	if ( (val1 * val2 < 0 or val2 * val3 < 0 or val3 * val1 < 0) )
		return false;

	return true;
}

void add( point a, vector<point>& hull )
{
	int idx = 0;
	int n = hull.size();
	ll pt = 1e18;

	for (int i = 0; i < n; i++)
	{
		ll d = dist( a, hull[i] );
		if ( d < pt )
			pt = d, idx = i;
	}

	int up = idx;
	bool chng = 0;
	while ( sign( a, hull[up], hull[ (up + 1) % n ] ) != 2 )
		up = (up + 1) % n, chng = 1;

	if (!chng)
	{
		while ( sign( a, hull[up], hull[ (n + up - 1) % n ] ) != 2 )
			up = (n + up - 1) % n;
	}

	chng = 0;

	int low = idx;

	while ( sign( a, hull[low], hull[ (n + low - 1) % n ]  ) != 1 )
		low = (n + low - 1) % n, chng = 1;

	if (!chng)
	{
		while ( sign( a, hull[low], hull[ (low + 1) % n ]  ) != 1 )
			low = (low + 1) % n, chng = 1;
	}

	int curr = up;
	if (up == low)
		curr = 0, low = n - 1, up = 0;
	ret.resize(0);
	ret.push_back(hull[up]);

	while (curr != low)
	{
		curr = (curr + 1) % n;
		ret.push_back(hull[curr]);
	}

	point b;
	b.x = a.x;
	b.y = a.y;
	ret.push_back(b);
	hh= ret;
}

long long int seed1, seed2;
int get_random() {
	seed1 = (seed1 * 1103515243 + 12345) % (2012345671);
	seed2 = (seed2 * 1092104927 + 54321) % (2094828103);
	int r = (seed1 * seed2) % 100000;
	return r;
}

ll ComputeArea(const vector<point> &p)
{
	ll area = 0;
	for (int i = 0; i < p.size(); i++)
	{
		int j = (i + 1) % p.size();
		area += p[i].x * p[j].y - p[j].x * p[i].y;
	}
	return area;
}

bool hoise = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for ( int t = 1; t <= tc; t++ )
	{
		p.clear();
		ret.clear();
		ret.resize(200007);
		hh.clear();

		int q;
		bool first = 1;
		cin >> q >> seed1 >> seed2;

		ll ans = 0, last = 0;

		for (int i = 0; i < q; i++)
		{
			ll t;
			point b;
			b.x = get_random();
			b.y = get_random();

			if(hoise)
			{
				// cout<<"ashe]n";
				if(!inside(b))
					add(b,ret);
			}
			else
			{
				p.push_back(b);

				if(p.size()>2)
					bord(), hoise= 1;
			}

			// cout<<i<<" "<<hh.size()<<endl;

			if( hh.size()>2 )
				last= ComputeArea(hh);

			ans += last;
		}

		cout <<"Case "<<t<<": "<< ans << "\n";
		hoise= 0;
	}
}