#include <bits/stdc++.h>
#define inf 100000000000000LL
#define ll long long
#define mx 1000007
using namespace std;

vector< vector<ll> > tree( 4LL*mx, {0LL,inf} );

ll f(vector<ll> line, int x){
	return line[0] * x + line[1];
}

void insert(vector<ll> line, int lo = 1, int hi = mx, int i = 1){
	int m = (lo + hi) / 2;
	bool left = f(line, lo) < f(tree[i], lo);
	bool mid = f(line, m) < f(tree[i], m);

	if(mid) swap(tree[i], line);

	if(hi - lo == 1) return;
	else if(left != mid) insert(line, lo, m, 2*i);
	else insert(line, m, hi, 2*i+1);
}

ll query(int x, int lo = 1, int hi = mx, int i = 1){
	int m = (lo+hi)/2;
	ll curr = f(tree[i], x);
	if(hi-lo==1) return curr;
	if(x<m) return min(curr, query(x, lo, m, 2*i));
	else return min(curr, query(x, m, hi, 2*i+1));
}

ll dp[mx];

int main()
{
	ll n,c;
	cin>>n>>c;

	ll h[n+5];

	for( int i=1;i<=n;i++ )
	{
		cin>> h[i];

		if(i>1)
			dp[i]= h[i]*h[i]+c+query( h[i] );

		insert( { -2*h[i], h[i]*h[i]+dp[i] } );
	}

	cout<< dp[n] <<"\n";
}
