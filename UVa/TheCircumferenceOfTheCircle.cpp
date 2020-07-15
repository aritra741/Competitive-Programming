#include <bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;

int main()
{
    double x1,x2,x3,y1,y2,y3;

    while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
    {
        double a1=y2-y1;
        double b1=x1-x2;
        double midx1=(x1+x2)/2.0;
        double midy1=(y1+y2)/2.0;
        double c1=b1*midx1-a1*midy1;

        double a2=y3-y1;
        double b2=x1-x3;
        double midx2=(x1+x3)/2.0;
        double midy2=(y1+y3)/2.0;
        double c2=b2*midx2-a2*midy2;

        double det= a1*b2-a2*b1;
        det=-det;

        double x= (a2*c1-a1*c2)/det;
        double y= (-b2*c1+b1*c2)/det;
        y=-y;

        double r= sqrt( (x-x1)*(x-x1)+(y-y1)*(y-y1) );

        cout<< setprecision(2) << fixed << 2.0*pi*r <<endl;

    }
}
