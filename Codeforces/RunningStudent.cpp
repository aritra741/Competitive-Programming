#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct point
{
    ll x,y;
}p[110], target;

double dist( point p )
{
    return sqrt( (p.x-target.x)*(p.x-target.x)+(p.y-target.y)*(p.y-target.y) );
}

int main()
{
    int n;
    double vb,vs;
    cin>>n>>vb>>vs;

    for(int i=0;i<n;i++)
        cin>>p[i].x,
        p[i].y= 0;

    cin>>target.x>>target.y;

    double mn= 1e18, d= 1e18;
    int idx= -1;

    for(int i=1;i<n;i++)
    {
        double D= dist( p[i] );
        double t1= p[i].x/vb;
        double t2= D/vs;
        double t= t1+t2;

        if( t<=mn and D < d )
        {
            mn= t;
            d= D;
            idx= i+1;
        }
    }

    cout<< idx <<endl;
}
