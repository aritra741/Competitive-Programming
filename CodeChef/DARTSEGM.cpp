#include<bits/stdc++.h>
#define ll long long
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
#define mx 50007
using namespace std;

struct PT{
    ll x, y;
    PT(){x = y = 0; }
    PT(ll _x, ll _y) {x = _x, y = _y; }
    PT operator-(const PT &a) const{
        return PT(x - a.x, y - a.y);
    }
    PT operator+(const PT &a) const{
        return PT(x + a.x, y + a.y);
    }
    PT operator*(ll a) const{
        return PT(x * a, y * a);
    }
    PT operator/(ll a) const{
        return PT(x / a, y / a);
    }
    ll val()
    {
        return x * x + y * y;
    }
    PT unit()
    {
        return (*this) / val();
    }
    void scan()
    {
        scanf("%lld %lld", &x, &y);
    }
    void print()
    {
        printf("(%lld, %lld)\n", x, y);
    }
};

ll dist(PT a, PT b)
{
    return (a - b).val();
}

vector<PT> tree[mx*4], ans, p, ret;

bool cmp( PT a, PT b )
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;

}

int sign( PT p, PT q, PT r )
{
    ll val= (q.y-p.y)*(r.x-q.x)-
            (q.x-p.x)*(r.y-q.y);

    val=-val;

    if(val<0)
        return 1;
    if(val>0)
        return 2;
    return 0;
}

void bord( vector<PT> &p )
{
    int k=0, n= p.size();
    ret.clear();
    ret.resize(n+7);
    sort(p.begin(),p.end(),cmp);

    for(int i=0; i<n; i++)
    {
        while(k>=2 and sign(ret[k-2], ret[k-1], p[i])!=2)
            k--;
        ret[k++]= p[i];
    }
    int t= k;
    for(int i=n-2; i>=0; i--)
    {
        while(k>t and sign( ret[k-2], ret[k-1], p[i] )!=2)
            k--;
        ret[k++]= p[i];
    }

    ret.resize(k-1);
}

void build( int node, int l, int r )
{
    if( l==r )
    {
        tree[node].push_back( p[l-1] );
//        cout<<" "<<tree[node].size()<<endl;
        return;
    }

    build( lchild, l, mid );
    build( rchild, mid+1, r );

    vector<PT>now;

    for(auto x: tree[lchild])
        now.push_back(x);
    for(auto x: tree[rchild])
        now.push_back(x);

    if(r-l+1>2)
    {
        bord(now);
        tree[node].swap(ret) ;
    }
    else
        for( int i=l-1;i<r;i++ )
            tree[node].push_back(p[i]);
}

void query( int node, int l, int r, int i, int j )
{
    if( l>j or r<i )
        return;
    if( l>=i and r<=j )
    {
       for( auto x: tree[node] )
            ans.push_back(x);
        return;
    }

    query( lchild, l, mid, i, j );
    query( rchild, mid+1, r, i, j );
}

int main()
{
    int n;
    scanf("%d", &n);

    p.resize(n);

    for( int i=0;i<n;i++ )
        p[i].scan();

    build( 1, 1, n );

    int q;
    scanf("%d", &q);

    while(q--)
    {
        int l,r;
        scanf("%d %d", &l,  &r);

        ans.clear();

        query( 1, 1, n, l, r );

        ll dis= 0;

        for( int i=0;i<ans.size();i++ )
            for( int j=i+1;j<ans.size();j++ )
                dis= max( dis, dist( ans[i], ans[j] ) );

        printf("%lld\n", dis);

    }
}

