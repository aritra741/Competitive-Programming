#include<bits/stdc++.h>
#define pi 3.14159
using namespace std;

double rad( double deg )
{
    return deg*pi/180.0;
}

int main()
{
    string t;
    cin>>t;
    while(1)
    {
        double r,th,gas;
        cin>>r>>gas>>th;

        th= min( th, 360-th );

        double s= r*rad(th);

        if( 5.00*gas>=s*2.00 )
            cout<<"YES "<<setprecision(0)<<fixed<<gas-(s*2.00)/5;
        else
            cout<<"NO "<<setprecision(0)<<fixed<<gas*5.00;

        cin>>t;
        cin>>t;

        if (t=="ENDOFINPUT")
            break;
        else
            cout<<endl;
    }
}
