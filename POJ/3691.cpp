#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include<complex>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
#define N 1007
char s[N];
int node[N][27];
int backnode[N];
int cnt[N];
bool ending[N];
int id;
char st[N];
int len[N];

inline void init()
{
	id = 0;
	for (int i = 0; i < 26; i++)
		node[id][i] = 0;
}

inline int newnode()
{
	id++;
	for (int i = 0; i < 26; i++)
	{
		node[id][i] = 0;
	}
	backnode[id] = 0;
	cnt[id] = 0;
	ending[id] = 0;
	return id;
}
inline void Insert()
{
	int u = 0;
	int n = strlen(st);
	for (int i = 0; i < n; i++)
	{
		int x = st[i] - 'A';
		if (!node[u][x]) node[u][x] = newnode();
		u = node[u][x];
	}
	ending[u] = 1;
}

inline void AhoCorasik()
{
	queue<int>q;
	for (int i = 0; i < 26; i++)
	{
		if (node[0][i])
		{
			q.push(node[0][i]);
			backnode[node[0][i]] = 0;
		}
	}
	while (!q.empty())
	{
		int u = q.front();
		int w = backnode[u];
		ending[u] |= ending[w];
		// cout<<u<<" "<<w<<endl;
		q.pop();
		for (int i = 0; i < 26; i++)
		{
			int v = node[u][i];
			if (v)
			{
				q.push(v);
				backnode[v] = node[backnode[u]][i];
			}
			else
			{
				node[u][i] = node[backnode[u]][i];
			}
		}
	}
}

int dp[1007][1007];
int vis[1007][1007];
string xx = "ACGT";
int n, pp;

int rec( int i, int x )
{
	if (i >= n)
		return  0;
	if ( vis[i][x] == pp )
		return dp[i][x];

	char c = s[i];
	int cur = node[x][c - 'A'];

	int ret = 1e5;

	if ( !ending[cur] )
	{
		ret = min( ret, rec( i + 1, cur ) );
	}

	for ( int j = 0; j < 4; j++ )
	{
		char y = xx[j];
		if ( !ending[node[x][y - 'A']] )
		{
			// cout<<" "<<xxt<<endl;
			ret = min( ret, 1 + rec( i + 1, node[x][y - 'A'] ) );
		}
	}

	vis[i][x] = pp;

	return dp[i][x] = ret;
}

int main()
{
	int m;
	int tc = 1;

	while (scanf("%d", &m) == 1 and m)
	{
		init();
		for ( int i = 0; i < m; i++ )
		{
			scanf("%s", st);
			Insert();
		}

		AhoCorasik();

		scanf("%s", s);
		n = strlen(s);
		pp++;

		int ans = rec( 0, 0 );

		if (ans > n)
			ans = -1;

		printf("Case %d: %d\n", tc++, ans);
	}
}
