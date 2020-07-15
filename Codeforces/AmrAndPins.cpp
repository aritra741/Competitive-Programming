#include <bits/stdc++.h>
using namespace std;
int main()
{
    double r,x,y,x1,y1;
    cin>>r>>x>>y>>x1>>y1;
    if(x==x1 && y==y1)
        cout<<0<<endl;
    else
    {
        double dis= sqrt ( (x1-x)*(x1-x) + (y1-y)*(y1-y) );
        dis= dis/(2.0*r);
        double ans= ceil(dis);
        cout<<ans<<endl;
    }
}
