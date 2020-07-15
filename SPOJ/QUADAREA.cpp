#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++)
    {
        double a,b,c,d;
        cin>>a>>b>>c>>d;
        double s=(a+b+c+d)/2.0;
        double ans=sqrt((s-a)*(s-b)*(s-c)*(s-d));
        cout<<setprecision(6)<<fixed<<ans<<endl;
    }
}
