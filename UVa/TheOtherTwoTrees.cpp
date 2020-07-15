#include <bits/stdc++.h>
using namespace std;
int main()
{
    double x1,y1,x2,y2;

    while(cin>>x1>>y1>>x2>>y2)
    {
        double mx= (x1+x2)/2;
        double my= (y1+y2)/2;
        double distx= x1-mx;
        double disty= y1-my;
        double ansx1= mx+disty;
        double ansy1= my+distx;
        double ansx2= mx-disty;
        double ansy2= my-distx;
        cout<<setprecision(10)<<fixed<<ansx1<<" "<<setprecision(10)<<fixed<<ansy2<<" "<<setprecision(10)<<fixed<<ansx2<<" "<<setprecision(10)<<fixed<<ansy1<<endl;
    }
}
