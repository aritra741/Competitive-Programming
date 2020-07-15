#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        double r1,r2,r3;
        cin>>r1>>r2>>r3;
        double ab=r1+r2;
        double bc=r1+r3;
        double ca=r2+r3;
        double s=ab+bc+ca;
        s/=2;
        double tri= sqrt( s*(s-ab)*(s-bc)*(s-ca) );
        double thc= acos((ca*ca+bc*bc-ab*ab)/(2*ca*bc));
        double thb= acos((ab*ab+bc*bc-ca*ca)/(2*bc*ab));
        double tha=  acos((ab*ab+ca*ca-bc*bc)/(2*ab*ca));
        double cirb= 0.5*r1*r1*thb;
        double cira= 0.5*r2*r2*tha;
        double circ= 0.5*r3*r3*thc;
        double totcir= cira+cirb+circ;
        double ans= tri-totcir;
        cout<<"Case "<<i<<": "<<setprecision(8)<<fixed<<ans<<endl;

        }
}
