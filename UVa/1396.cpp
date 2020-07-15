#include<cstdio>
#include<algorithm>
#include<vector>
#include<math.h>
#define mx 107
#define inf 2e18
#define EPS 1e-8
using namespace std;

struct PT{
    double x, y;
    PT(){x = y = 0; }
    PT(double _x, double _y) {x = _x, y = _y; }
    PT operator-(const PT &a) const{
        return PT(x - a.x, y - a.y);
    }
    PT operator+(const PT &a) const{
        return PT(x + a.x, y + a.y);
    }
    PT operator*(double a) const{
        return PT(x * a, y * a);
    }
    PT operator/(double a) const{
        return PT(x / a, y / a);
    }
    double val()
    {
        return sqrt(x * x + y * y);
    }
    PT unit()
    {
        return (*this) / val();
    }
    void scan()
    {
        scanf("%lf %lf", &x, &y);
    }
    void print()
    {
        printf("(%.4f, %.4f)", x, y);
    }
};

PT p[107];

int EQ(double x)
{
    if(fabs(x)<EPS) return 0;
    else if(x>0) return 1;
    else return -1;
}

double dot(PT p, PT q)
{
    return p.x*q.x+p.y*q.y;
}
double dist2(PT p, PT q)
{
    return dot(p-q,p-q);
}
double distPoint(PT p, PT q)
{
    return sqrt(dot(p-q,p-q));
}
double cross(PT p, PT q)
{
    return p.x*q.y-p.y*q.x;
}

PT RotateCCW90(PT p)
{
    return PT(-p.y,p.x);
}

bool areLinesParallel(PT a, PT b, PT c, PT d)
{
    if(fabs(cross(a-b,c-d))<EPS)
        return true;
    return false;
}

PT ComputeLineIntersection(PT a, PT b, PT c, PT d)
{
    double a1,b1,c1,a2,b2,c2;
    a1 = a.y - b.y;
    b1 = b.x - a.x;
    c1 = cross(a, b);
    a2 = c.y - d.y;
    b2 = d.x - c.x;
    c2 = cross(c, d);
    double D = a1 * b2 - a2 * b1;
    return PT((b1 * c2 - b2 * c1) / D,(c1 * a2 - c2 * a1) / D);
}
struct HP
{
    PT p, v;
    double arg;
    HP(){}
    HP(PT a, PT b): p(a), v(b-a), arg(atan2(v.y,v.x)){}
    bool operator < (const HP &h) const { return arg < h.arg; }
    friend PT intersection( HP a, HP b )
    {
        double t= cross(b.v, a.p-b.p)/cross(a.v,b.v);
        return a.p+a.v*t;
    }
};

vector <PT> halfPlaneIntersection( vector<HP> h )
{
    int n= h.size(), l= 0, r= -1;
    sort( h.begin(), h.end() );
    vector<PT>hull, p(n);
    HP q[mx]; q[++r]= h[0];
    for( int i=1;i<n;i++ )
    {
        while( l<r and cross( h[i].v, p[r-1]-h[i].p )<-EPS ) r--;
        while( l<r and cross( h[i].v, p[l]-h[i].p )<-EPS ) l++;
        q[++r]= h[i];
        if( fabs( cross( q[r].v, q[r-1].v ) )<-EPS )
        {
            r--;
            if( cross( q[r].v, h[i].p-q[r].p )>= -EPS ) q[r]= h[i];
        }
        if( l<r ) p[r-1]= intersection( q[r-1], q[r] );
    }
    while( l<r and cross( q[l].v, p[r-1]-q[l].p )<-EPS ) r--;
    if( r-l<=1 ) return hull;
    p[r]= intersection( q[l], q[r] );
    while( l<=r ) hull.push_back(p[l++]);
    return hull;
}

int main()
{
    int n;

    while( scanf("%d", &n)==1 and n )
    {
        for( int i=0;i<n;i++ )
            p[i].scan();

        double l= 0, r= 2e8;

        double ans;

        for( int j=0;j<100;j++ )
        {
            double m= (l+r)/2;

            vector<HP> h;

            for( int i=0, j=1;i<n;i++, j= (j+1)%n )
            {
                PT qq= RotateCCW90(p[j]-p[i]);
                qq= qq*(m/qq.val());
                h.push_back( HP( p[i]+qq, p[j]+qq ) );
            }

            vector<PT> poly= halfPlaneIntersection(h);

            if( poly.size() )
                l= m, ans= m;
            else
                r= m;
        }

        printf("%.10f\n", ans);
    }
}
