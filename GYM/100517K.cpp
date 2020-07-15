#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct PT
{
    ll x, y;
    PT() {}
    PT(ll x, ll y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &p)  const
    {
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p)  const
    {
        return PT(x-p.x, y-p.y);
    }
    PT operator * (ll c)     const
    {
        return PT(x*c,   y*c  );
    }
    PT operator / (ll c)     const
    {
        return PT(x/c,   y/c  );
    }
};
ll cross(PT p, PT q)
{
    return p.x*q.y-p.y*q.x;
}

int main()
{
    freopen( "kingdom.in", "r", stdin );
    freopen( "kingdom.out", "w", stdout );

    int n;

    while(cin>>n and n )
    {
        PT p[n+7];

        for( int i=0; i<n; i++ )
            cin>>p[i].x>>p[i].y;

        PT a,b;

        cin>>a.x>>a.y;
        cin>>b.x>>b.y;

        int l= 1, r= 1;
        ll ans= 0;

        for( int i=0; i<n; i++ )
        {
            while( cross( p[(l+1)%n]-p[i], a-p[i] )>=0 and cross( p[(l+1)%n]-p[i], b-p[i] )>=0 )
                l= (l+1)%n;
            while( cross( p[r]-p[i], a-p[i] )>0 or cross( p[r]-p[i], b-p[i] )>0 )
                r= (r+1)%n;

            if(l!=r)
                ans+= ( r-l-1+n )%n ;
        }

        cout<<ans/2<<"\n";
    }
}
