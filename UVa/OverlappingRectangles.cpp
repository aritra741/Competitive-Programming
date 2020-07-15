#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        getchar();

        int x1,x2,x3,x4,y1,y2,y3,y4;
        cin>>x1>>y1>>x2>>y2;
        cin>>x3>>y3>>x4>>y4;

        if(x3>=x2 or x1>=x4 or y1>=y4 or y3>=y2)
            cout<<"No Overlap"<<endl;
        else
            cout<<max(x1,x3)<<" "<<max(y1,y3)<<" "<<min(x2,x4)<<" "<<min(y2,y4)<<endl;
        if(tc)
            cout<<endl;
    }
}
