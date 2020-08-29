#include <bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int t=1; t<=tc; t++)
    {
        double x1,x2,r1,y1,y2,r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        double bc= sqrt ( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );

        if(r1+r2<=bc)
        {
            cout<<"Case "<<t<<": 0.0000000"<<endl;
        }
        else if(r1+r2>=bc and fabs(r1-r2)<bc)
        {
            double s= (r1+r2+bc)/2.0;
            double abc= sqrt( s*(s-r2)*(s-r1)*(s-bc) );
            double AD= 4.0*abc/bc;

            double th2 = acos( (r2*r2+bc*bc-r1*r1)/(2.0*r2*bc) );
            double th1 = acos( (r1*r1+bc*bc-r2*r2)/(2.0*r1*bc) );

            double sector1= 0.5*r1*r1*2*th1;
            double sector2= 0.5*r2*r2*2*th2;

            double triangle1= 0.5 * r1 * sin(th1*2) * r1;
            double triangle2= 0.5 * r2 * sin(th2*2) * r2;

            double segment1= sector1 - triangle1;
            double segment2= sector2 - triangle2;
            double ans= segment1 + segment2;

            cout<<"Case "<<t<<": "<<setprecision(10)<<fixed<<ans<<endl;
           // cout<<"YES1"<<endl;
        }
         else
            {
                double r3= min(r1,r2);
                double area= pi*r3*r3;
                cout<<"Case "<<t<<": "<<setprecision(10)<<fixed<<area<<endl;
                //cout<<"YES2"<<endl;
            }
    }
}
