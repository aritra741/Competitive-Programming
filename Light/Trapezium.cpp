#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    double a,b,c,d;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        cin>>a>>b>>c>>d;
        double osh=abs(b*b-d*d);
        double diff=abs(a-c);
        double y=(osh+diff*diff)/(2*diff);
        double mx=max(b,d);
        double x=sqrt( mx*mx-y*y );
        double ans=0.5*x*(a+c);

        printf("Case %d: %f\n", i, ans);
    }


}

