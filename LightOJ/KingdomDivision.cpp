#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    for(int i=1;i<=tc;i++)
    {
        double a,b,c;
        cin>>a>>b>>c;
        double p= a*c/b;
        if(b-p<=0)
        {
            cout<<"Case "<<i<<": "<<"-1"<<endl;
            continue;
        }
        double ans=(a*c+p*c+a*p+b*p)/(b-p);
        cout<<"Case "<<i<<": "<<setprecision(10)<<fixed<<ans<<endl;
    }
}
