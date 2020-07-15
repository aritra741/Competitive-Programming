#include<cstdio>
#include<algorithm>
#include<math.h>
#define EPS 1e-9
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
        printf("(%.10f, %.10f)", x, y);
    }
};

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

// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c)
{
    double r = dot(b-a,b-a);
    if (fabs(r) < EPS) return a;
    r = dot(c-a, b-a)/r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b-a)*r;
}

// compute distance from c to segment between a and b
double DistancePointSegment(PT a, PT b, PT c)
{
    return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}

double SegmentSegmentDistance( PT a, PT b, PT c, PT d )
{
    return min( DistancePointSegment( a, b, c ), min( DistancePointSegment( a, b, d ), min( DistancePointSegment( c,d,b ), DistancePointSegment( c,d,a ) ) ) );
}

int main()
{
    int n,m;

    while( scanf("%d %d", &n, &m)==2 and n+m )
    {
        PT p[n+5], q[m+5];

        for( int i=0;i<n;i++ )
            p[i].scan();
        for( int i=0;i<m;i++ )
            q[i].scan();

        p[n]= p[0];
        q[m]= q[0];

        int miny_in_p= 0;

        for( int i=1;i<n;i++ )
            if( p[i].y<p[miny_in_p].y )
                miny_in_p= i;

        int maxy_in_q= 0;

        for( int i=1;i<m;i++ )
            if( q[i].y>q[maxy_in_q].y )
                maxy_in_q= i;

        double ans= 4e18;

        for( int i=0;i<n;i++ )
        {
            while( cross( p[miny_in_p+1]-p[ miny_in_p ], q[maxy_in_q]-p[miny_in_p] )
                  <= cross( p[miny_in_p+1]-p[miny_in_p], q[maxy_in_q+1]-p[miny_in_p] ) )
                    maxy_in_q= (maxy_in_q+1)%m;

            ans= min( ans, SegmentSegmentDistance( p[miny_in_p], p[miny_in_p+1], q[maxy_in_q], q[maxy_in_q+1] ) );
            miny_in_p= (miny_in_p+1)%n;
        }

        printf("%.10f\n", ans);
    }
}
