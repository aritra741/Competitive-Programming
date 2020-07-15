#include <bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;

int main()
{
    int r;
    double ang;
    string s;

    while(cin>>r>>ang>>s)
    {
        r+=6440.00;

        if(ang>180.00)
        {
            while(ang>180.00)
                ang-=180.00;
            ang= 180.00-ang;
        }

        if(s=="min")
            ang/=60.0;
        ang*= pi/180.00;

        double chord= cos(ang)*2.0*r*r;
        chord-=(2.0*r*r);
        if(chord!=0.00)
            chord=-chord;
        if(chord<0.00)
            chord= 0.00;
        else
            chord= sqrt(chord);

        double arc= r*ang;

        cout<<setprecision(6)<<fixed<<arc<<" "<<chord<<endl;
    }
}
