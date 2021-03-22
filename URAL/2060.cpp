#include <bits/stdc++.h>
#define ll long long
using namespace std;


const int MAXN = 300007;
const int N = 26;

ll pref[MAXN], suff[MAXN], hit[MAXN];
bool f;

struct Palindromic_Tree
{
	int next[MAXN][N];
	int fail[MAXN];
	long long cnt[MAXN]; // কতবার palindromic sub-string টি মুল string এর মধ্যে

	int num[MAXN]; //many palindromic sub-string ends in that position
	int start[MAXN];
	int end[MAXN];
	int len[MAXN];
	int S[MAXN];
	int last;
	int n;
	int p; // total node(number of unique palindrome in string)


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

	int get_fail(int x) { // KMP
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
	string str;

	cin >> str;

	tt.init();

	for (int i = 0; i < str.size(); i++)
	{
		tt.add(str[i], i);
	}

	reverse(str.begin(), str.end());

	tt.init();
	f= 1;

	for( int i=0;i<str.size();i++ )
	{
		tt.add(str[i], i);
	}

	ll ans= 0;

	for( int i=0;i<str.size();i++ )
	{
		// cout<<i<<" "<<pref[i]<<endl;
		ans+= pref[i-1]*suff[str.size()-i-1];
	}

	printf("%lld\n", ans);
}