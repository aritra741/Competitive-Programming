#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x1,x2,y1,y2,r1,r2;
    cin>>x1>>y1>>r1
       >>x2>>y2>>r2;

    double dist= sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) );

    if( r1+r2<=dist )
    {
        dist-=(r1+r2);
        dist/=2.0;
    }

    else if( max(r2,r1)-min(r2,r1)>dist )
    {
        dist= max(r2,r1)-min(r2,r1)-dist;
        dist/=2.0;
    }

    else
        dist= 0.0;

    cout<<setprecision(8)<<fixed<< dist <<endl;
}
