#include <bits/stdc++.h>
#define pi acos(-1.)
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        double l;
        cin>>l;

        double w= 6.0*l/10.0;
        double rect= w*l;

        double r= 2.0*l/10.0;
        double circ= pi*r*r;

        cout<<setprecision(2)<<fixed<< circ <<" "<< rect-circ <<endl;
    }
}
