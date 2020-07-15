#include <bits/stdc++.h>
using namespace std;
int main()
{
    double n,r;
    while(scanf("%lf %lf", &r,&n)==2)
    {
        double area=0.5*r*r*n*sin(4*acos(0.0)/n);
        cout<<setprecision(3)<<fixed<<area<<endl;
    }
}
