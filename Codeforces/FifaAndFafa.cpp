#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct point
{
    double x,y;
};

double dist( point a, point b )
{
    return sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) );
}

int main()
{
    double r;
    point center, fafa;

    cin>>r>>center.x>>center.y>>fafa.x>>fafa.y;

    double d= dist(center, fafa);
    if(d>r)
        d= 0.0;
    d+=r;

    double dx= center.x-fafa.x;
    double dy= center.y-fafa.y;
    double dr= sqrt( dx*dx+dy*dy );
    double D= fafa.x*center.y-center.x*fafa.y;
    int sign= (dy<0)?-1:1;

    point inter1, inter2;
    inter1.x= ( D*dy+sign*dy*dx*sqrt( r*r*dr*dr-D*D ) )/(dr*dr);
    inter1.y= ( -D*dx+fabs(dy)*sqrt( r*r*dr*dr-D*D ) )/(dr*dr);
    inter2.x= ( D*dy-sign*dy*dx*sqrt( r*r*dr*dr-D*D ) )/(dr*dr);
    inter2.y= ( -D*dx-fabs(dy)*sqrt( r*r*dr*dr-D*D ) )/(dr*dr);

    double dist1= dist( inter1, fafa );
    double dist2= dist( inter2, fafa );

    point inter;

    if(dist1>dist2)
        inter.x= inter1.x,
        inter.y= inter1.y;
    else
        inter.x= inter2.x,
        inter.y= inter2.y;

    double x= (inter.x+fafa.x)/2.0;
    double y= (inter.y+fafa.y)/2.0;

    cout<<x<<" "<<y<<endl;
}
