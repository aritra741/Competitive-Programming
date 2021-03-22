#include <bits/stdc++.h>
#define N 100007
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
char s[N];
int node[N][27];
int vis[N];
int backnode[N];
int cnt[N];
pii endpos[N];
int id;
char st[N];
int ans[N];
vector<int>pos[N];
int len[N];
 

int BIG (int k) {
	string ss(s) , t(st) ;
	ss = t + "#" + ss ;
	int n = ss.size() , m = t.size() ;
	vector <int> p(n) ;
	for (int i = 1 ; i < n ; i++) {
		int j = p[i - 1] ;
		while (j > 0 and ss[i] != ss[j]) {
			j = p[j - 1] ;
		}
		if (ss[i] == ss[j]) j++ ;
		p[i] = j ;
	}
	vector <int> v ;
	for (int i = m + m ; i < n ; i++) {
		if (p[i] == m) v.emplace_back(i) ;
	}
	if (v.size() < k) return -1 ;
	int ans = 1e9 ;
	for (int i = k - 1 ; i < v.size() ; i++) {
		ans = min(ans, v[i] - v[i - k + 1]) ;
	}
	return ans + m ;
}
 

inline void init()
{
	id=0;
	for(int i=0;i<26;i++)
		node[id][i]=0;
}
 
inline int newnode()
{
	id++;
	for(int i=0;i<26;i++)
	{
		node[id][i]=0;
	}
	backnode[id]=0;
	cnt[id]=0;
	endpos[id]=pii(-1,-1);
	return id;
}
inline void Insert(int i,int k)
{
	int u=0;
	int n=strlen(st);
	for(int i=0;i<n;i++)
	{
		int x=st[i]-'a';
		if(!node[u][x]) node[u][x]=newnode();
		u=node[u][x];
	}
	endpos[u]=pii(i,k);
}
inline void AhoCorasik()
{
	queue<int>q;
	for(int i=0;i<26;i++)
	{
		if(node[0][i])
		{
			q.push(node[0][i]);
			backnode[node[0][i]]=0;
		}
	}
	while(!q.empty())
	{
		int u=q.front();
		int w=backnode[u];
		q.pop();
		for(int i=0;i<26;i++)
		{
			int v=node[u][i];
			if(v)
			{
				q.push(v);
				backnode[v]=node[backnode[u]][i];
			}
			else
			{
				node[u][i]=node[backnode[u]][i];
			}
		}
	}
}
 
void f()
{
	int u= 0;
	for( int i=0;s[i];i++ )
	{
		int v= u= node[u][s[i]-'a'];
 
		while(v!=0)
		{
			if(endpos[v].ff!=-1)
				pos[v].push_back(i);
			v= backnode[v];
		}
	}
 
	for( int i=1;i<=id;i++ )
	{
		if( endpos[i].ff!=-1 )
		{
			int idx= endpos[i].ff;
			int k= endpos[i].ss;
 
			int val= INT_MAX;
 
			if( pos[i].size()<k )
				ans[idx]= -1;
			else
			{
				for( int a=0,b=k-1;b<pos[i].size();a++,b++ )
					val= min( val, pos[i][b]-pos[i][a]+len[idx] );
				ans[idx]= val;
			}
		}
	}
}
 
int main()
{
	scanf("%s", s);
 
	int m;
	scanf("%d", &m);
 
	for( int i=1;i<=m;i++ )
	{
		int k;
 
		scanf("%d", &k);
		scanf("%s", st);
 		
		if(strlen(st)>100)
		{
			ans[i]= BIG(k);
			continue;
		}

		Insert(i,k);
		len[i]= strlen(st);
	}
 
	AhoCorasik();
	f();
 
	for( int i=1;i<=m;i++ )
		printf("%d\n", ans[i]);
}