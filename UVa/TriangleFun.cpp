#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        double ax,ay,bx,by,cx,cy;
        cin>>ax>>ay>>bx>>by>>cx>>cy;
        double ans=abs ( (ax*(by-cy) +bx*(cy-ay) +cx*(ay-by))/2 );
        ans=ans/7;
        cout<<setprecision(0)<<fixed<<ans<<endl;
    }
}
