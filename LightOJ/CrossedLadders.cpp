#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        double x,y,h;
        cin>>x>>y>>h;
        double low=1e-7;
        double high=max(x,y);
        for(int i=1;i<=100;i++)
        {
            double d=(high+low)/2.0;
            double a= 1.0/sqrt( x*x - d*d );
            double b= 1.0/sqrt( y*y - d*d );
            if(a+b<(1/h))
                low=d;
            else
                high=d;

        }

        cout<<"Case "<<t<<": "<<setprecision(10)<<fixed<<low<<endl;
    }
}
