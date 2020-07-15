#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        double l,w;
        cin>>l>>w;

        double x2=  4.0*(l+w)-sqrt( 16.0*(l+w)*(l+w)-48.0*l*w );
        x2/=24.0;

        double ans= (l-2.0*x2)*(w-2.0*x2)*x2;

        cout<<"Case "<<t<<": "<<setprecision(10)<<fixed<<ans<<endl;

    }
}
