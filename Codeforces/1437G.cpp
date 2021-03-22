#include <bits/stdc++.h>
#define N 300007
#define ll long long
#define pii pair<int,int>
#define ff first
#define ss second
#define mid (l+r)/2
#define lchild 2*node
#define rchild lchild+1
using namespace std;

std::vector<int> adj[N];
int node[N][27];
int backnode[N];
bool ending[N];
int id;
int depth[N];
int konta[N];
int st[N], en[N];
int val[N];
bool invalid[N];
set<pii, greater<pii>> tree[4*N];
string qq;

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
    ending[id] = 0;
    depth[id] = 0;
    return id;
}
inline void Insert(int idx, string &st)
{
    int u = 0;
    int n = st.size();
    for (int i = 0; i < n; i++)
    {
        int x = st[i] - 'a';
        if (!node[u][x]) node[u][x] = newnode();
        u = node[u][x];
        depth[u] = i + 1;
    }

    konta[idx]= u;
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
        invalid[w]= 1;
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

int T;

void dfs( int u )
{
    st[u]= ++T;
    for(auto v:adj[u])
        dfs(v);
    en[u]= T;
}

void update( int node, int l, int r, int i, int j, int idx, int x, bool f )
{
    if(l>j or r<i)
        return;
    if(l>=i and r<=j)
    {   
        if(f)
            tree[node].erase( pii(val[idx],idx) );
        tree[node].insert( pii(x,idx) );
        return;
    }

    update( lchild, l, mid, i, j, idx, x, f );
    update( rchild, mid+1, r, i, j, idx, x, f );
}

int query( int node, int l, int r, int i )
{
    int q= -1;
    if( tree[node].size() )
        q= (*tree[node].begin()).first;

    if(l>i or r<i)
        return -1;
    if(l>=i and r<=i)
    {
        if( tree[node].size() )
            return max(q,(*tree[node].begin() ).first);
        return q;
    }

    int q1;
    if(i<=mid)
        q1= query( lchild, l, mid, i );
    else
        q1= query( rchild, mid+1, r, i );
    
    return max(q,q1);
}

int search( int i, int x )
{
    if(i>=qq.size())
        return -1;
    int y= qq[i]-'a';
    int ret= -1;

    if( node[x][y] )
    {
        int nn= node[x][y];
        ret= max( ret, query( 1, 1, T, st[nn] ) );
        ret= max( ret, search( i+1, nn ) );
    }
    else
    {
        int nn= node[backnode[x]][y];
        ret= max( ret, query( 1, 1, T, st[nn] ) );   
        ret= max( ret, search( i+1, nn ) );
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;

    for( int i=1;i<=n;i++ )
    {
        string s;
        cin>>s;

        val[i]= 0;
        Insert(i,s);
    }

    AhoCorasik();

    dfs(0);

    for( int i=1;i<=n;i++ )
        update( 1, 1, T, st[konta[i]], en[konta[i]], i, 0, 0 );

    while(q--)
    {
        int tp;
        cin>>tp;

        if(tp==1)
        {
            int p,x;
            cin>>p>>x;

            update( 1, 1, T, st[konta[p]], en[konta[p]], p, x, 1 );
            val[p]= x;
        }
        else
        {
            cin>>qq;

            cout<< search( 0, 0 ) <<"\n";
        }
    }
}   
