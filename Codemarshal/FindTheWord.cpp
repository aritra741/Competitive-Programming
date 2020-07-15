#include<bits/stdc++.h>
#define lchild 2*node+1
#define rchild lchild+1
#define M 200007
using namespace std;
const int kinds = 256;///maximum ASCII value of any character of the string
int nn;
char str[M];
int K, buc[M], r[M], sa[M], X[M], Y[M], high[M];
bool cmp(int *r, int a, int b, int x)
{
    return (r[a] == r[b] && r[a+x] == r[b+x]);
}
vector<int>saa;
int lcp[M];

void suffix_array_DA(int n, int m)
{
    int *x = X, *y = Y, i, j, k = 0, l;
    memset(buc, 0, sizeof(buc));
    for(i = 0; i < n; i++)
        buc[ x[i]=str[i] ]++;
    for(i = 1; i < m; i++)
        buc[i] += buc[i-1];
    for(i = n-1; i >= 0; i--)
        sa[--buc[x[i]]] = i;
    for(l = 1, j = 1; j < n; m = j, l <<= 1)
    {
        j = 0;
        for(i = n-l; i < n; i++)
            y[j++] = i;
        for(i = 0; i < n; i++)
            if(sa[i] >= l)
                y[j++] = sa[i]-l;
        for(i = 0; i < m; i++)
            buc[i] = 0;
        for(i = 0; i < n; i++)
            buc[ x[y[i]] ]++;
        for(i = 1; i < m; i++)
            buc[i] += buc[i-1];
        for(i = n-1; i >= 0; i--)
            sa[ --buc[ x[y[i]] ]] = y[i];
        for(swap(x, y), x[sa[0]] = 0, i = 1, j = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i-1], sa[i], l) ? j-1 : j++;
    }
    for(i = 1; i < n; i++)
        r[sa[i]] = i;
    for(i = 0; i < n-1; high[r[i++]] = k)
        for(k ? k--: 0, j = sa[r[i]-1]; str[i+k] == str[j+k]; k++);
}
void suffix_array_construction(string s)
{
    int n=s.size();
    for(int i=0; i<n; i++)
        str[i]=s[i];
    str[n]='\0';
    suffix_array_DA(n+1,kinds);

    for(int i=1; i<=n; i++)
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
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
}

string ss;

int pos[M];
int rmqtree[M*4];
vector<int>tree[M*4];

void build( int node, int l, int r )
{
    if( l==r )
    {
        tree[node].push_back( saa[l] );
        return;
    }

    int mid= (l+r)/2;

    build( lchild, l, mid );
    build( rchild, mid+1, r );

    merge( tree[lchild].begin(), tree[lchild].end(), tree[rchild].begin(), tree[rchild].end(), back_inserter(tree[node]) );
}

void buildrmq( int node, int l, int r )
{
    if( l==r )
    {
        rmqtree[node]= lcp[l];
        return;
    }

    int mid= (l+r)/2;

    buildrmq( lchild, l, mid );
    buildrmq( rchild, mid+1, r );

    rmqtree[node]= min( rmqtree[lchild], rmqtree[rchild] );
}

int query( int node, int l, int r, int i, int j, int x, int y )
{
    if( l>j or r<i )
        return 0;
    if( l>=i and r<=j )
    {
        int first= lower_bound( tree[node].begin(), tree[node].end(), x )-tree[node].begin();
        int baad= upper_bound( tree[node].begin(), tree[node].end(), y )-tree[node].begin();
        baad= tree[node].size()-baad;
        first= tree[node].size()-first;

        int ase= first-baad;

        return ase;
    }

    int mid= (l+r)/2;

    int q1= query( lchild, l, mid, i, j, x, y );
    int q2= query( rchild, mid+1, r, i, j, x, y );

    return q1+q2;
}

int rmq( int node, int l, int r, int i, int j )
{
    if( l>j or r<i )
        return 1e9;
    if( l>=i and r<=j )
        return rmqtree[node];

    int mid= (l+r)/2;

    int q1= rmq( lchild, l, mid, i, j );
    int q2= rmq( rchild, mid+1, r, i, j );

    return min( q1, q2 );
}

void traverse( int node, int l, int r )
{
    if(l==r)
    {
        tree[node].clear();
        return;
    }

    int mid= (l+r)/2;

    traverse( lchild, l, mid );
    traverse( rchild, mid+1, r );

    tree[node].clear();
}

/// leftmost position return kore
int baame( int koi, int len )
{
    koi--;
    int l= 0, r= koi, ans= koi+1;

    while(l<=r)
    {
        int mid= (l+r)/2;

        int val= rmq( 0, 0, nn-1, mid, koi );
        if(val>1e8)
            val= 0;
        if( val<len )
            l= mid+1;
        else
            r= mid-1, ans= mid;
    }

    return ans;
}

/// right e extra koyta ase, sheta return kore
int daane( int koi, int len )
{
    int l= koi, r= nn-1, ans= 0;

    while(l<=r)
    {
        int mid= (l+r)/2;

        int val= rmq( 0, 0, nn-1, koi, mid );
        if(val>1e8)
            val= 0;
        if( val<len )
            r= mid-1;
        else
            l= mid+1, ans= mid;
    }

    return max(0,ans-koi+1);
}

char s[100007];

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%s", s);

        int n= strlen(s);

        suffix_array_construction(s);
        lcp_construction(s,saa);

        nn= saa.size();

        build( 0, 0, nn-1 );
        buildrmq( 0, 0, nn-1 );

        for( int i=0; i<nn; i++ )
            pos[ saa[i] ]= i;

        int q;
        scanf("%d", &q);

        while(q--)
        {
            int a,b,c,d;
            scanf("%d %d %d %d", &a, &b, &c, &d);

            if( d-c+1>b-a+1 )
            {
                printf("0\n");
                continue;
            }

            a--, b--, c--, d--;

            int l= pos[c];
            int len= d-c+1;

            int left= baame( l, len );
            int right= daane( l, len );

            int rangebaame= left;
            int rangedaane= pos[c]+right;

            int ans= query( 0, 0, nn-1, rangebaame, rangedaane, a, b-(d-c+1)+1 );

            printf("%d\n", ans);
        }

        saa.clear();
        memset( lcp, 0, sizeof(lcp) );
        traverse( 0, 0, nn-1 );
    }
}
