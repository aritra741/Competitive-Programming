#include <bits/stdc++.h>
using namespace std;

bool ifCollinear(double x1,double y1, double x2, double y2, double x3, double y3)
{
    double det= (x2*y3- y2*x3) - (x1*y3 -y1*x3) + (x1*y2- y1*x2);
    if(det==0)
        return 1;
    else
        return 0;
}
int main()
{
    int tc;
    cin>>tc;
    cout<<"INTERSECTING LINES OUTPUT"<<endl;
    for (int i=1;i<=tc;i++)
    {

        double x1,x2,x3,x4,y1,y2,y3,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        double A1= y2-y1;
        double B1= x1-x2;
        double A2= y4-y3;
        double B2= x3-x4;
        double C1= A1*x1+ B1*y1;
        double C2= A2*x3 + B2*y3;
        double det= A1*B2 - A2*B1;
        bool det1= ifCollinear(x1,y1,x2,y2,x3,y3);
        bool det2= ifCollinear(x2,y2,x3,y3,x4,y4);
        if(det1 && det2)
            cout<<"LINE"<<endl;
        else if(det==0)
            cout<<"NONE"<<endl;
        else
        {

            double x= (B2*C1-B1*C2)/det;
            double y= (A1*C2- A2*C1)/det;
            if(y==-0.00)
                y=0.00;
            cout<<"POINT "<<setprecision(2)<<fixed<<x<<" "<<setprecision(2)<<fixed<<y<<endl;

        }
    }
    cout<<"END OF OUTPUT"<<endl;
}
