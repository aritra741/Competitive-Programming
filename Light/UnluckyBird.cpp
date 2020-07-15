#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        double v1,v2,v3,a1,a2;
        cin>>v1>>v2>>v3>>a1>>a2;

        double d= pow(v1, 2)/(2*a1) + pow(v2,2)/(2*a2);
        double time= max( v1/a1, v2/a2 );
        double bird= v3*time;

        cout<<"Case "<<t<<": "<<setprecision(10)<<fixed<<d<<" "<<bird<<endl;
    }
}
