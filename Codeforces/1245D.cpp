#include<bits/stdc++.h>
#define mx 2007
#define ll long long
using namespace std;

ll c[mx];
bool boshe[mx];

struct point
{
    ll x,y;
};

struct edge
{
    ll u, v, w;
};

bool cmp( edge a, edge b )
{
    return a.w<b.w;
}

int par[mx+mx*mx], Size[mx+mx*mx];

void init( int n )
{
    for( int i=0; i<=n; i++ )
        par[i]= i, Size[i]= 1;
}

int Find( int u )
{
    if( par[u]==u )
        return u;
    return par[u]= Find( par[u] );
}

void unite( int u, int v )
{
    int paru= Find( u );
    int parv= Find( v );

    if( paru!=parv )
    {
        if( Size[paru]>Size[parv] )
            par[parv]= paru, Size[paru]+= Size[parv];
        else
            par[paru]= parv, Size[parv]+= Size[paru];
    }
}

vector<point>v;
vector<edge>ee;
vector<int> stat;
vector<edge> con;
set<int>st;
ll k[mx];
bool done[mx];

int main()
{
    int n;
    cin>>n;

    init(n);

    for( int i=0; i<n; i++ )
    {
        point p;
        cin>>p.x>>p.y;

        v.push_back(p);
    }

    for( int i=0; i<n; i++ )
        for( int j=i+1; j<n; j++ )
        {
            edge e;
            e.u= i;
            e.v= j;
            e.w= abs(v[i].x-v[j].x)+abs(v[i].y-v[j].y);

            ee.push_back(e);
        }

    for( int i=0; i<n; i++ )
    {
        edge e;
        e.u= i;
        e.v= i;

        cin>> e.w;

        c[i]= e.w;

        ee.push_back(e);
    }

    for( int i=0; i<n; i++ )
        cin>>k[i];

    for( int i=0; i<ee.size(); i++ )
    {
        if( ee[i].u==ee[i].v )
            break;
        ee[i].w*= k[ee[i].u]+k[ee[i].v];
    }

    sort( ee.begin(), ee.end(), cmp );

    ll ans= 0;

    for( int i=0; i<ee.size(); i++ )
    {
        int p= ee[i].u;
        int q= ee[i].v;
        ll w= ee[i].w;

        if( !boshe[Find(p)] or !boshe[Find(q)] )
        {
            if( Find(p)==Find(q) and p!=q )
                continue;
            if( p!=q )
            {
                if( boshe[Find(p)] or boshe[Find(q)] )
                    boshe[Find(p)]= 1, boshe[Find(q)]= 1;

                unite( p,q );
            }
            if( p==q )
                stat.push_back( p+1 ), boshe[Find(p)]= 1;
            else
                con.push_back(ee[i]);

            ans+= w;
        }
    }

    cout<< ans <<endl;
    cout<< stat.size() <<endl;

    for( int i=0; i<stat.size(); i++ )
        cout<<stat[i]<<" ";
    cout<<endl;

    cout<<con.size()<<endl;

    for( int i=0; i<con.size(); i++ )
        cout<< con[i].u+1 <<" "<< con[i].v+1 <<endl;
}
