#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    int tc=1;
    while(scanf("%d : %d", &a, &b)==2)
    {
        double high=400;
        double low=1e-6;
        for(int j=0;j<100;j++)
        {
            double w=(low+high)/2.0;
            double x=w/b;
            double l=a*x;
            double diag=sqrt( l*l + w*w );
            double rad= diag/2.0;
            double th= acos( 1-(0.5*(w*w)/(rad*rad) ) );
            double per= 2*rad*th + 2*l;
            if(per>400)
                high=w;
            else
                low=w;
        }
        double l=a* (low/b);
        cout<<"Case "<<tc++<<": "<<setprecision(10)<<fixed<<l<<" "<<low<<endl;

    }
}
