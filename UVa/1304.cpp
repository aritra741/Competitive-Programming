#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#define eps 1e-7
#define inf 3e9
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

int EQ(double x)
{
    if(fabs(x)<eps)
        return 0;
    else if(x>0)
        return 1;
    else
        return -1;
}

double cross(PT p, PT q)
{
    return p.x*q.y-p.y*q.x;
}

bool areLinesParallel(PT a, PT b, PT c, PT d)
{
    if(fabs(cross(a-b,c-d))<eps)
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

double ComputeSignedArea(const vector<PT> &p)
{
    double area = 0;
    for(int i = 0; i < p.size(); i++)
    {
        int j = (i+1) % p.size();
        area += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    return area / 2.0;
}

double ComputeArea(const vector<PT> &p)
{
    return fabs(ComputeSignedArea(p));
}


vector<PT> halfPlaneIntersection(const vector<PT> &poly, pair<PT,PT> ln)
{
    vector<PT> ret;
    int s=poly.size();
    for(int i=0; i<s; i++)
    {
        double c1=cross(ln.second-ln.first,poly[i]-ln.first);
        double c2=cross(ln.second-ln.first,poly[(i+1)%s]-ln.first);
        if(EQ(c1)>=0)
            ret.push_back(poly[i]);
        if(EQ(c1*c2)<0)
        {
            if(!areLinesParallel(poly[i],poly[(i+1)%s],ln.first,ln.second))
            {
                ret.push_back(ComputeLineIntersection(poly[i],poly[(i+1)%s],ln.first,ln.second));
            }
        }
    }
    return ret;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1; t<=tc; t++ )
    {
        int n;
        scanf("%d", &n);

        vector<PT>arr(n);

        for( int i=0; i<n; i++ )
            scanf("%lf %lf", &arr[i].x, &arr[i].y);

        vector<PT>poly;
        poly.push_back( PT(-inf,-inf) );
        poly.push_back( PT(inf,-inf) );
        poly.push_back( PT(inf,inf) );
        poly.push_back( PT(-inf,inf) );

        for( int i=0,j=n-1; i<n; j= i++ )
            poly= halfPlaneIntersection( poly, { arr[i], arr[j] } );

        printf("%.2f\n", ComputeArea(poly));
    }
}

