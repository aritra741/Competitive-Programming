#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a,b,c;

    while(cin>>a>>b>>c)
    {
        double s= (a+b+c)/2.0;
        double up= (s-a)*(s-b)*(s-c);
        double ans= up;
        if(s>0.00)
            ans= up/s;
        ans= sqrt(ans);

        if(s==0.00)
            ans= 0.00;

        cout<<"The radius of the round table is: "<<setprecision(3)<<fixed<<ans<<endl;
    }
}
