#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x1,x2,x3,y1,y2,y3;
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3){

    double a1= x2-x1;
    double b1= y2-y1;
    double midx1= (x1+x2)/2.0;
    double midy1= (y1+y2)/2.0;
    double c1= a1*midx1+b1*midy1;

    double a2= x1-x3;
    double b2= y1-y3;
    double midx2= (x1+x3)/2.0;
    double midy2= (y1+y3)/2.0;
    double c2= a2*midx2+b2*midy2;

    double det= a1*b2-a2*b1;

    double x= (b2*c1-b1*c2)/det;
    double y= (a1*c2-a2*c1)/det;

    double r= sqrt( (x-x1)*(x-x1)+(y-y1)*(y-y1) );

    cout<<"(x ";

    if(x<0)
        cout<<"+ ";
    else
        cout<<"- ";

    cout<<setprecision(3)<<fixed<<abs(x)<<")^2 + (y ";

    if(y<0)
        cout<<"+ ";
    else
        cout<<"- ";

    cout<<setprecision(3)<<fixed<<abs(y)<<")^2 = "<<r<<"^2\n";

    cout<<"x^2 + y^2 ";

    if(x<0)
        cout<<"+ ";
    else
        cout<<"- ";

    cout<<setprecision(3)<<fixed<<abs(2*x)<<"x ";

    if(y<0)
        cout<<"+ ";
    else
        cout<<"- ";

    cout<<setprecision(3)<<fixed<<abs(2*y)<<"y ";

    double extra= x*x+y*y-r*r;

    if(extra<0)
        cout<<"- ";
    else
        cout<<"+ ";

    cout<<setprecision(3)<<fixed<<abs(extra)<<" = 0\n\n";
    }

}
