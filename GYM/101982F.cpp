#include<bits/stdc++.h>
#define ll long long
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
#define mx 100007
using namespace std;

struct event
{
    int y1, y2, x;

    event() {}
    event( int a, int b, int c )
    {
        x= a;
        y1= b;
        y2= c;
    }
};

vector<event>vv;

bool cmp( event a, event b )
{
    return a.x<b.x;
}

int yvals[mx*2];
int tree[mx*16];
bool state[mx*16];

void Switch( int node, int l, int r )
{
    int tot= yvals[r]-yvals[l];
    tree[node]= tot-tree[node];
}

void prop( int node, int l, int r )
{
    if( state[node] )
    {
        Switch(node,l,r);
        state[node]^= 1;
        state[lchild]^= 1;
        state[rchild]^= 1;
    }
}

void update( int node, int l, int r, int i, int j )
{
    prop(node,l,r);
    if( yvals[l]>j or yvals[r]<i )
        return;
    if( yvals[l]>=i and yvals[r]<=j )
    {
        state[node]^= 1;
        prop(node,l,r);
        return;
    }

    if(l+1>=r)
        return;

    update( lchild, l, mid, i, j );
    update( rchild, mid, r, i, j );

    tree[node]= tree[lchild]+tree[rchild];
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

        yvals[++y]= y1;
        yvals[++y]= y2;
        vv.push_back(event( x1, y1, y2 ));
        vv.push_back(event( x2, y1, y2 ));
    }

    sort( vv.begin(), vv.end(), cmp );
    sort( yvals+1, yvals+1+y );

    int k= 1;

    for( int i=2; i<=y; i++ )
        if( yvals[i]!=yvals[k] )
            yvals[++k]= yvals[i];

    int m= k;

    update( 1, 1, m, vv[0].y1, vv[0].y2 );

    ll ans= 0;

    for( int i=1; i<vv.size(); i++ )
    {
        ans+= 1LL*tree[1]*( vv[i].x-vv[i-1].x );
        update( 1, 1, m, vv[i].y1, vv[i].y2 );
    }

    printf("%lld\n", ans);
}
