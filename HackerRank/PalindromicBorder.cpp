#include <bits/stdc++.h>
#define ll long long
using namespace std;


const int MAXN = 100007;
const int N = 26;
#define mod 1000000007

ll pref[MAXN], suff[MAXN], hit[MAXN];
bool f;
ll sum[MAXN];
ll ans;

struct Palindromic_Tree
{
	int next[MAXN][N];
	int fail[MAXN];
	long long cnt[MAXN]; 

	int num[MAXN]; 
	int start[MAXN];
	int end[MAXN];
	int len[MAXN];
	int S[MAXN];
	int last;
	int n;
	int p; 


	int newnode(int l)
	{
		for (int i = 0; i < N; i++) next[p][i] = 0;
		cnt[p] = 0;
		num[p] = 0;
		len[p] = l;
		hit[p]= 0;
		return p++;
	}

	void init()
	{
		p = 0;
		newnode(0);
		newnode(-1);
		last = 0;
		n = 0;
		S[n] = -1;
		fail[0] = 1;
	}

	int get_fail(int x) {
		while (S[n - len[x] - 1] != S[n]) x = fail[x];
		return x;
	}

	void add(int c, int i)
	{
		c -= 'a';
		S[++n] = c;

		int cur = get_fail(last);

		if (!next[cur][c]) {
			int now = newnode(len[cur] + 2);
			end[now] = i;
			start[now] = i - len[cur] - 2 + 1;
			fail[now] = next[get_fail(fail[cur])][c];
			next[cur][c] = now;
			num[now] = num[fail[now]] + 1;
		}

		last = next[cur][c];
		int agey= get_fail(last);
		// hit[last]= 1+hit[agey];
		// cout<<i<<" "<<last<<" "<<num[last]<<endl;

		if(!f)
			pref[i]= num[last];
		else
			suff[i]= num[last];

		cnt[last]++;
	}

	void count()
	{
		for (int i = p - 1; i >= 0; --i) cnt[fail[i]] += cnt[i];
	}

	void print()
	{
		for (int i = 1; i <= p - 2; i++)
		{
			printf("%c ", S[i] + 'a');
		}
		printf("\n");

		for (int i = 2; i < p; i++)
		{
			printf("%lld ", cnt[i]);
		}
		printf("\n");
		for (int i = 2; i < p; i++)
		{
			printf("%d ", num[i]);
		}
		printf("\n");
		for (int i = 2; i < p; i++)
		{
			printf("%d ", start[i]);
		}
		printf("\n");
		for (int i = 2; i < p; i++)
		{
			printf("%d ", end[i]);
		}
		printf("\n");
	}
} tt;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;

	cin >> str;

	tt.init();

	for (int i = 0; i < str.size(); i++)
	{
		tt.add(str[i], i);
	}

	tt.count();

	sum[0]= pref[0];

	for( int i=2;i<tt.p;i++ )
	{
		ll tot= tt.cnt[i];
		ans= (ans+(tot*(tot-1))/2)%mod;
	}

	printf("%lld\n", ans);
}