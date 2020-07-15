#include <bits/stdc++.h>
#define PI 2*acos(0.0)
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        int r1,r2,h,p;
        cin>>r1>>r2>>h>>p;
        double R=(double)p*(r1-r2)+(double)r2*h;
        R/=h;
        double volume=(PI*p)/3;
        volume*=(R*R+r2*r2+r2*R);
        cout<<"Case "<<i<<": "<<setprecision(10)<<fixed<<volume<<endl;
    }
}
