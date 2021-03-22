#include <bits/stdc++.h>
#define N 100007
#define ll long long
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

std::vector<int> adj[N];
string s[N];
int node[N][27];
int vis[N];
int val[N];
int backnode[N];
int cnt[N];
bool ending[N];
int id;
int ln[N];
int arr[N];
ll ans;
int depth[N];
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
    val[id] = 0;
    ending[id] = 0;
    depth[id] = 0;
    return id;
}
inline void Insert(string &st)
{
    int u = 0;
    int n = st.size();
    for (int i = 0; i < n; i++)
    {
        int x = st[i] - 'a';
        if (!node[u][x]) node[u][x] = newnode();
        u = node[u][x];
        val[u] = max(val[u], arr[i]);
        cnt[u]++;
        depth[u] = i + 1;
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
        adj[w].push_back(u);
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

void dfs(int x)
{
    ans = max( ans, 1LL * depth[x] * val[x] * cnt[x] );

    for ( auto v : adj[x] )
    {
        dfs(v);
    }
}

int traverse(int x)
{
    for ( auto v : adj[x] )
    {
        val[x] = max(val[x], traverse(v));
    }

    return val[x];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("exciting.in", "r", stdin);

    int tc;
    cin >> tc;

    while (tc--)
    {
        init();

        ans = 0;
        int n;
        cin >> n;

        for ( int i = 0; i < n; i++ )
        {
            cin >> s[i];
            ln[i] = s[i].size();
        }

        for ( int i = 0; i < n; i++ )
        {
            for ( int j = 0; j < ln[i]; j++ )
                cin >> arr[j];

            Insert(s[i]);
        }

        AhoCorasik();
        int k = traverse(0);
        dfs( 0 );

        for( int i=0;i<=id;i++ )
            adj[i].clear();

        cout << ans << "\n";
    }
}
