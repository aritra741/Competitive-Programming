#include<bits/stdc++.h>
#define ll long long
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
#define mx 100007
using namespace std;

vector<int>shuru[mx*2],shesh[mx*2];

int ans[mx*2];
int yvals[mx*2];
int tree[mx*16];
int startidx[mx*2], endidx[mx*2];
int lazy[mx*16];

void prop( int node, int l, int r )
{
    if( lazy[node] )
    {
        lazy[lchild]+= lazy[node];
        lazy[rchild]+= lazy[node];
        tree[lchild]+= lazy[node];
        tree[rchild]+= lazy[node];
        lazy[node]= 0;
    }
}

void update( int node, int l, int r, int i, int j, int v )
{
    prop(node,l,r);
    if( yvals[l]>j or yvals[r]<i )
        return;
    if( yvals[l]>=i and yvals[r]<=j )
    {
        lazy[node]+= v;
        tree[node]+= v;
        prop(node,l,r);
        return;
    }

    update( lchild, l, mid, i, j, v );
    update( rchild, mid+1, r, i, j, v );

    tree[node]= max(tree[lchild],tree[rchild]);
}

int query( int node, int l, int r, int x )
{
    prop(node,l,r);
    if( yvals[l]>x or yvals[r]<x )
        return -2e9;
    if( yvals[l]>=x and yvals[r]<=x )
        return tree[node];

    if( x<=yvals[mid] )
        return query( lchild, l, mid, x );
    else
        return query( rchild, mid+1, r, x );
}

int main()
{
    int n;
    scanf("%d", &n);

    int y= 0;

    for( int i=1; i<=n; i++ )
    {
        int x1,x2,y1,y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        startidx[i]= y2;
        endidx[i]= y1;
        yvals[++y]= y1;
        yvals[++y]= y2;
    }

    sort( yvals+1, yvals+1+y );

    int k= 1;

    for( int i=2; i<=y; i++ )
        if( yvals[i]!=yvals[k] )
            yvals[++k]= yvals[i];

    int m= k;

    for( int i=1; i<=n; i++ )
    {
        startidx[i]= lower_bound( yvals+1, yvals+m+1, startidx[i] )-yvals;
        endidx[i]= lower_bound( yvals+1, yvals+m+1, endidx[i] )-yvals;

        shuru[ startidx[i] ].push_back(i);
        shesh[ endidx[i] ].push_back(i);

        update( 1, 1, m, yvals[startidx[i]], yvals[endidx[i]], 1 );
    }

    for( int i=1; i<=m; i++ )
        ans[i]= query( 1, 1, m, yvals[i] );

    int MX= 0;

    for( int i=1;i<=m;i++ )
    {
        for( int j=0;j<shuru[i].size();j++ )
            update( 1, 1, m, yvals[startidx[shuru[i][j]]], yvals[endidx[shuru[i][j]]], -1 );
        MX= max( MX, ans[i]+tree[1] );
        for( int j=0;j<shesh[i].size();j++ )
            update( 1, 1, m, yvals[startidx[shesh[i][j]]], yvals[endidx[shesh[i][j]]], 1 );
    }

    printf("%d\n", MX);
}

