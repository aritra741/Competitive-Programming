#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc,h,m,dif,h1,m1;
    cin>>tc;
    while(tc--)
    {
        scanf("%d:%d", &h,&m);
        int sml=(h*60+m);
        if(sml<720)
        {
            dif=720-sml;
            h1=dif/60;
            m1=dif%60;

        }
        else
        {
            dif=1440-sml;
            h1=dif/60;
            m1=dif%60;
        }
        if(h1==0)
            h1=12;
        if(h1<10)
            cout<<"0"<<h1<<":";
        else
            cout<<h1<<":";
        if(m1<10)
            cout<<"0"<<m1<<endl;
        else
            cout<<m1<<endl;
    }
}
