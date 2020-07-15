#include <bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        double r1,r2,r3;
        cin>>r1>>r2>>r3;

        double a= r1+r2;
        double b= r1+r3;
        double c= r3+r2;

        double s= a+b+c;
        s/=2.0;

        double tri= sqrt( s*(s-a)*(s-b)*(s-c) );

        double th1= (a*a+b*b-c*c)/(2.0*a*b);
        th1= acos(th1);
        double th2= (a*a+c*c-b*b)/(2.0*a*c);
        th2= acos(th2);
        double th3= (b*b+c*c-a*a)/(2.0*b*c);
        th3= acos(th3);
        double arc1= 0.5*r1*r1*th1;
        double arc2= 0.5*r2*r2*th2;
        double arc3= 0.5*r3*r3*th3;

        double totarc= arc1+arc2+arc3;

        double ans= tri-totarc;

        cout<<setprecision(6)<<fixed<< ans <<endl;
    }
}
