#include <bits/stdc++.h>
using namespace std;
int main()
{
    double b,s;
    int tc=1;

    while(1)
    {
        cin>>b>>s;
        if(b+s==0)
            break;

        if(b==1)
        {
            cout<<"Case "<<tc++<<": :-\\"<<endl;
            continue;
        }

        double fir= min(1.00, s/b);
        double sec= min(1.00, (s-1)/(b-1));

        if(fir==sec)
            cout<<"Case "<<tc++<<": :-|"<<endl;
        else if(fir>sec)
            cout<<"Case "<<tc++<<": :-("<<endl;
        else
            cout<<"Case "<<tc++<<": :-)"<<endl;

    }
}
