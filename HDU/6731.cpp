#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pii pair<int,int>
#define ll long long
using namespace std;
using namespace __gnu_pbds;

struct PT
{
    int x, y;
    PT() {}
    PT(int x, int y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &p)  const
    {
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p)  const
    {
        return PT(x-p.x, y-p.y);
    }
    PT operator * (int c)     const
    {
        return PT(x*c,   y*c  );
    }
    PT operator / (int c)     const
    {
        return PT(x/c,   y/c  );
    }
};

struct chash{
    int operator()(pii x) const { return x.first*31+x.second; }
};

bool operator < ( PT a, PT b )
{
    if(a.y==b.y)
        return a.x<b.x;
    return a.y<b.y;
}

PT RotateCCW90(PT p)
{
    return PT(-p.y,p.x);
}

PT RotateCW90(PT p)
{
    return PT(p.y,-p.x);
}

gp_hash_table<pii,int, chash>mpp[2007];

int main()
{
    int n,q;
    scanf("%d %d", &n, &q);

    PT p[n];

    for( int i=0; i<n; i++ )
        scanf("%lld %lld", &p[i].x,&p[i].y);

    for( int i=0; i<n; i++ )
    {
        for( int j=0; j<n; j++ )
        {
            if(i==j)
                continue;

            int xx,yy;
            xx= p[j].x-p[i].x;
            yy= p[j].y-p[i].y;
            int g= llabs(__gcd(xx,yy));

            if(g)
                xx/= g, yy/= g;

            mpp[i][ {xx,yy} ]++;
        }
    }

    while(q--)
    {
        PT qq;
        scanf("%lld %lld", &qq.x, &qq.y);

        gp_hash_table<pii,int,chash>mp;
        ll ans= 0;

        for( int i=0; i<n; i++ )
        {
            int xx,yy;
            xx= p[i].x-qq.x;
            yy= p[i].y-qq.y;

            int g= llabs(__gcd(xx,yy));
            if(g)
                xx/= g, yy/= g;
            mp[ {xx,yy} ]++;
        }

        for( int i=0; i<n; i++ )
        {
            int xx,yy;
            xx= p[i].x-qq.x;
            yy= p[i].y-qq.y;

            int g= llabs(__gcd(xx,yy));
            if(g)
                xx/= g, yy/= g;

            PT now= RotateCCW90( PT(xx,yy) );

            if( mp.find({now.x,now.y})!=mp.end() )
                ans+= mp[ {now.x,now.y} ];
        }

        ll ans2= 0;

        for( int i=0;i<n;i++ )
        {
            int xx,yy;
            xx= qq.x-p[i].x;
            yy= qq.y-p[i].y;

            int g= llabs(__gcd(xx,yy));
            if(g)
                xx/= g, yy/= g;

            PT now= RotateCCW90( PT(xx,yy) );

            if( mpp[i].find({now.x,now.y})!=mpp[i].end() )
                ans2+= mpp[i][ {now.x,now.y} ];

            now= RotateCW90( PT(xx,yy) );

            if( mpp[i].find({now.x,now.y})!=mpp[i].end() )
                ans2+= mpp[i][ {now.x,now.y} ];
        }

        ans+= ans2;

        printf("%lld\n", ans);
    }
}
