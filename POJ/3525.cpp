#include <cstdio>
#include<iostream>
#include <cmath>
using namespace std;

double moves[8][2]= { {-0.5,0}, {0.5,0}, {-0.5,0.5}, {0.5,-0.5}, {0,0.5}, {0.5,0.5}, {0,-0.5}, {-0.5,-0.5} };
int n;

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

double dot(PT p, PT q)
{
    return p.x*q.x+p.y*q.y;
}

double dist(PT a, PT b)
{
    return (a - b).val();
}

double totdist( double xx, double yy )
{
    double ret= 0;
    PT qq(xx,yy);

    for( int i=0; i<n; i++ )
        ret+= dist( qq, p[i] );

    return ret;
}

int main()
{
    while(scanf("%d", &n)==1)
    {
        double totx= 0, toty= 0;

        for( int i=0;i<n;i++ )
            p[i].scan(), totx+= p[i].x, toty+= p[i].y;

        double last= 4e18;

        double nowx= totx/n;
        double nowy= toty/n;

        while(1)
        {
            double mn= 4e18;
            double porex= nowx;
            double porey= nowy;

            for( int i=0;i<8;i++ )
            {
                double tot= 0;
                double xx= nowx+moves[i][0];
                double yy= nowy+moves[i][1];

                tot= totdist( xx, yy );

                if( tot<mn )
                {
                    mn= tot;
                    porex= nowx+moves[i][0];
                    porey= nowy+moves[i][1];
                }
            }

            if(mn>last)
                break;
            last= mn;
            nowx= porex;
            nowy= porey;
        }

        printf("%.0f\n", last);
    }
}

