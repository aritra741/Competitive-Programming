#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct PT
{
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &p)  const
    {
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p)  const
    {
        return PT(x-p.x, y-p.y);
    }
    PT operator * (double c)     const
    {
        return PT(x*c,   y*c  );
    }
    PT operator / (double c)     const
    {
        return PT(x/c,   y/c  );
    }
};

vector<PT>ret(107), p;

bool cmp( PT a, PT b )
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

double dist( PT a, PT b )
{
    return sqrt(((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}

double area( PT p, PT q, PT r )
{
    double x[]= {p.x, q.x, r.x};
    double y[]= {p.y, q.y, r.y};

    double a= 0;
    int j= 2;

    for(int i=0; i<3; i++)
    {
        a+=(x[j]+x[i])*(y[j]-y[i]);
        j= i;
    }

    return fabs(a);
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

void bord()
{
    int k=0, n= p.size();
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

int main()
{
    int t= 1, n;

    while( scanf("%d", &n)==1 and n )
    {
        for( int i=0; i<n; i++ )
        {
            PT pp;
            scanf("%lf %lf", &pp.x, &pp.y);

            p.push_back(pp);
        }

        ret.resize(n+5);
        bord();

        int m= ret.size();

        double ans= 4e18;

        if( m>2 )
            for( int i=0,j=1; i<m; i++ )
            {
                while( area( ret[i], ret[ (i+1)%m ], ret[j] )<area( ret[i], ret[ (i+1)%m ], ret[(j+1)%m] ) )
                    j= ( j+1 )%m;
                ans= min( ans, area( ret[i], ret[(i+1)%m], ret[j] )/dist( ret[i],ret[(i+1)%m] ) );
            }
        else
            ans= 0;

        printf("Case %d: %.2f\n", t++, ans);

        p.clear();
    }
}
