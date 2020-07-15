#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a,b,c,d;
    cin>>a>>b>>c>>d;

    double ans= 0.0;

    for(int i=1;i<100000;i++)
        ans+= (a/b)*pow( (1.00-(c/d))*(1.00-(a/b)), i-1.00);

    cout<<setprecision(7)<<fixed<< ans <<endl;
}
