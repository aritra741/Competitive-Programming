#include<bits/stdc++.h>
#define ll long long
#define mx 60007
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
using namespace std;

struct vv
{
    bool st;
    int x, minY, maxY;

    vv( int xx, int y1, int y2, bool stt )
    {
        x= xx;
        minY= y1;
        maxY= y2;
        st= stt;
    }

    bool operator < ( const vv& v ) const
    {
        return x<v.x;
    }
};

int n, m, yy[mx*2];
int koyta[mx*16], tree[mx*16];
vector<vv>v;

void update( int node, int l, int r, int i, int j, bool st )
{
    if( yy[l]>j or yy[r]<i )
        return;

    if( yy[l]>=i and yy[r]<=j )
    {
        if(st)
            koyta[node]++;
        else
            koyta[node]--;

        if( koyta[node] )
            tree[node]= yy[r]-yy[l];
        else
            tree[node]= tree[lchild]+tree[rchild];

        return;
    }

    if(l+1>=r)
        return;

    update( lchild, l, mid, i, j, st );
    update( rchild, mid, r, i, j, st );

    if( koyta[node] )
        tree[node]= yy[r]-yy[l];
    else
        tree[node]= tree[lchild]+tree[rchild];
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1; t<=tc; t++ )
    {
        int n;
        scanf("%d", &n);

        m= 0;

        for( int i=0; i<n; i++ )
        {
            int x1,x2,y1,y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

            yy[++m]= y1;
            yy[++m]= y2;

            v.push_back( vv( x1,y1,y2,1 ) );
            v.push_back( vv( x2,y1,y2,0 ) );
        }

        sort( yy+1, yy+m+1 );
        sort( v.begin(), v.end() );

        int x= 1;

        for( int i=2; i<=m; i++ )
            if( yy[i]!=yy[x] )
                yy[++x]= yy[i];

        m= x;

        ll ans= 0;

        update( 1, 1, m, v[0].minY, v[0].maxY, v[0].st );

        for( int i=1; i<v.size(); i++ )
        {
            ans+= 1LL*tree[1]*(v[i].x-v[i-1].x);
            update( 1, 1, m, v[i].minY, v[i].maxY, v[i].st );
        }

        printf("Case %d: %lld\n", t, ans);

        memset( tree, 0, sizeof(tree) );
        memset( koyta, 0, sizeof(koyta) );
        v.clear();
    }
}
