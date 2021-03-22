#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define ff first
#define ss second
#define M 200007
using namespace std;

const int Maxn = 200005;
const int M_Log = 20;
int arr[Maxn], n;

const int kinds = 256;///maximum ASCII value of any character of the string
int nn;
char str[M];
int K, buc[M], r[M], sa[M], X[M], Y[M], high[M];
bool cmp(int *r, int a, int b, int x)
{
	return (r[a] == r[b] && r[a + x] == r[b + x]);
}
vector<int>saa;
int lcp[M];

void suffix_array_DA(int n, int m)
{
	int *x = X, *y = Y, i, j, k = 0, l;
	memset(buc, 0, sizeof(buc));
	for (i = 0; i < n; i++)
		buc[ x[i] = str[i] ]++;
	for (i = 1; i < m; i++)
		buc[i] += buc[i - 1];
	for (i = n - 1; i >= 0; i--)
		sa[--buc[x[i]]] = i;
	for (l = 1, j = 1; j < n; m = j, l <<= 1)
	{
		j = 0;
		for (i = n - l; i < n; i++)
			y[j++] = i;
		for (i = 0; i < n; i++)
			if (sa[i] >= l)
				y[j++] = sa[i] - l;
		for (i = 0; i < m; i++)
			buc[i] = 0;
		for (i = 0; i < n; i++)
			buc[ x[y[i]] ]++;
		for (i = 1; i < m; i++)
			buc[i] += buc[i - 1];
		for (i = n - 1; i >= 0; i--)
			sa[ --buc[ x[y[i]] ]] = y[i];
		for (swap(x, y), x[sa[0]] = 0, i = 1, j = 1; i < n; i++)
			x[sa[i]] = cmp(y, sa[i - 1], sa[i], l) ? j - 1 : j++;
	}
	for (i = 1; i < n; i++)
		r[sa[i]] = i;
	for (i = 0; i < n - 1; high[r[i++]] = k)
		for (k ? k-- : 0, j = sa[r[i] - 1]; str[i + k] == str[j + k]; k++);
}
void suffix_array_construction(string s)
{
	int n = s.size();
	for (int i = 0; i < n; i++)
		str[i] = s[i];
	str[n] = '\0';
	suffix_array_DA(n + 1, kinds);

	for (int i = 1; i <= n; i++)
		saa.push_back(sa[i]);
}
void lcp_construction(string const& s, vector<int> const& p)
{
	int n = s.size();
	vector<int> rank(n, 0);
	for (int i = 0; i < n; i++)
		rank[p[i]] = i;
	int k = 0;

	for (int i = 0; i < n; i++)
	{
		if (rank[i] == n - 1)
		{
			k = 0;
			continue;
		}
		int j = p[rank[i] + 1];
		while (i + k < n && j + k < n && s[i + k] == s[j + k])
			k++;
		lcp[rank[i]] = k;
		if (k)
			k--;
	}
}

string ss;

int shuru[M], konta[M], pos[M], sz[M];

struct wtree {
	int s[Maxn], tree[M_Log][Maxn], L[M_Log][Maxn];
	long long ls[M_Log][Maxn], SL;
	void build(int l, int r, int d)
	{
		if (l == r)return;
		int mid = (l + r) >> 1, cnt = 0, lc = l, rc = mid + 1, ec = 0;
		for (int i = l; i <= r; i++) if (tree[d][i] < s[mid])cnt++; // **
		for (int i = l; i <= r; i++)
		{
			if ((tree[d][i] < s[mid]) || (tree[d][i] == s[mid] && ec < (mid - l + 1 - cnt))) // **
			{
				tree[d + 1][lc++] = tree[d][i];
				ls[d][i] = ls[d][i - 1] + tree[d][i];
				if (tree[d][i] == s[mid])ec++;
			}
			else
			{
				tree[d + 1][rc++] = tree[d][i];
				ls[d][i] = ls[d][i - 1];
			}
			L[d][i] = L[d][l - 1] + lc - l; 
		}
		build(l, mid, d + 1);
		build(mid + 1, r, d + 1);
	}
	void init(int *arr, int n)
	{
		for (int i = 1; i <= n; i++)
		{
			tree[0][i] = arr[i];
			s[i] = tree[0][i];
		}
		sort(s + 1, s + n + 1); // **
		build(1, n, 0);
	}

	int kth(int l, int r, int d, int x, int y, int k)
	{	//1,n,0,x,y,k
		if (l == r) {
			SL += tree[d][l];
			return tree[d][l];
		}
		int cnt = L[d][y] - L[d][x - 1];
		int mid = (l + r) >> 1;
		if (cnt >= k)
		{
			int newx = L[d][x - 1] - L[d][l - 1];
			int newy = L[d][y] - L[d][l - 1];
			return kth(l, mid, d + 1, l + newx, l + newy - 1, k);
		}
		else
		{
			int newx = x - l - (L[d][x - 1] - L[d][l - 1]);
			int newy = y - l + 1 - (L[d][y] - L[d][l - 1]);
			SL += ls[d][y] - ls[d][x - 1];
			return kth(mid + 1, r, d + 1, mid + 1 + newx, mid + newy, k - cnt);
		}
	}
	
	int LTE(int l, int r, int d, int x, int y, int k)
	{	//1,n,0,x,y,k
		if (l == r) {
			if (l > y || l < x)return 0;
			// SL += tree[d][l] * (tree[d][l] <= k); // **
			return tree[d][l] <= k; // **
		}
		int cnt = L[d][y] - L[d][x - 1], mid = (l + r) >> 1;
		if (s[mid] <= k) // **
		{
			int newx = x - l - (L[d][x - 1] - L[d][l - 1]);
			int newy = y - l + 1 - (L[d][y] - L[d][l - 1]);
			// SL += ls[d][y] - ls[d][x - 1];
			return cnt + LTE(mid + 1, r, d + 1, mid + 1 + newx, mid + newy, k);
		}
		else
		{
			int newx = L[d][x - 1] - L[d][l - 1];
			int newy = L[d][y] - L[d][l - 1];
			return LTE(l, mid, d + 1, l + newx, l + newy - 1, k);
		}
	}
}tree;

ll ans[M];
int occ[M];
int last[M], idx[M];
int t[M][21], lg2[M];

void f( int n )
{
    int i, j, k, m, l, r, q;
    lg2[1] = 0;
    for (i = 2; i <=n; i++) lg2[i] = lg2[i / 2] + 1;
    for (i = 1; i <= n; i++) t[i][0] = lcp[i];
    for (j = 1; j <= 20; j++) for (i = 1; i + (1 << (j - 1)) <= n; i++) t[i][j] = min(t[i][j-1], t[i + (1 << (j - 1))][j - 1]);
}
 
int squery( int l, int r )
{
    int k = lg2[r - l + 1];
    int ans = min(t[l][k], t[r - (1 << k) + 1][k]);
    
    return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	string s;

	int gelo = 0;
	std::vector<int> pp;

	for ( int i = 1; i <= n; i++ )
	{
		string t;
		cin >> t;

		sz[i] = t.size();

		if (i>1)
			s += "$";

		s += t;

		shuru[i] = gelo;
		pp.push_back(gelo);
		gelo += t.size() + 1;

	}

	suffix_array_construction(s);
	lcp_construction(s, saa);

	nn = saa.size();

	reverse(saa.begin(), saa.end());
	saa.push_back(-1);
	reverse(saa.begin(), saa.end());

	for( int i=nn-1;i>=1;i-- )
		lcp[i]= lcp[i-1];
	lcp[0]= 0;

	f(nn);

	for ( int i = 1; i <= nn; i++ )
		konta[ saa[i] ] = i;
	for ( int i = 1; i <= n; i++ )
		pos[i] = konta[ shuru[i] ];

	sort( pp.begin(), pp.end() );

	int ii=1;
	// for( auto x: saa )
	// {
	// 	if(x==-1)
	// 		continue;
	// 	for( int i=x;i<s.size();i++ )
	// 		cout<<s[i];
	// 	cout<<" "<<lcp[ii++]<<" \n";
	// }

	for( int i=nn;i>=1;i-- )
	{
		if( s[saa[i]]=='$' )
			continue;

		int p= upper_bound( pp.begin(), pp.end(), saa[i] )-pp.begin();
		
		idx[i]= p;

		if(last[p])
			occ[i]= last[p];
		else
			occ[i]= nn+7;

		last[p]= i;
	}

	tree.init(occ, nn);

	for( int i=1;i<=nn;i++ )
	{
		if(s[saa[i]]=='$')
			continue;

		int id= idx[i];
		int l= 1, r= sz[id]-(saa[i]-shuru[id]+1)+1;
		int len= 0;
		int A= i, B= i;

		while(l<=r)
		{
			int mid=(l+r)/2;

			int l1= 1, r1= i-1;
			int a= i, b= i-1;

			while(l1<=r1)
			{
				int mid1= (l1+r1)/2;

				int rmq= squery(mid1, i-1);

				if(rmq<mid)
					l1= mid1+1;
				else
					r1= mid1-1, a= mid1;
			}

			l1= i, r1= nn;

			while(l1<=r1)
			{
				int mid1= (l1+r1)/2;

				int rmq= squery( i, mid1 );

				if(rmq<mid)
					r1= mid1-1;
				else
					b= mid1, l1= mid1+1;
			}

			b++;
			A= a, B= b;
			int unq= tree.LTE(1,nn,0,a,b,b);
			unq= b-a+1-unq;

			if(unq>=k)
				len= mid, l= mid+1;
			else
				r= mid-1;
		}

		// cout<<i<<" "<<A<<" "<<B<<" "<<len<<endl;

		ans[id]+= len;
	}

	for( int i=1;i<=n;i++ )
		cout<<ans[i]<<" ";
}