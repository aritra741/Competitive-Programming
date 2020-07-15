#include <bits/stdc++.h>
using namespace std;
int main()
{
    double  p,q,r,s;

    while(cin>>p>>q>>r>>s)
    {
        int i;
        double ans=1;

        for (i=0;i<q and i<s;i++)
        {
            double up=1;
            up*=(p-i);
            up/=(i+1);
            double down=1;
            down*=(r-i);
            down/=(i+1);

            ans*=up/down;
        }

        int j=i;

        while(i<q)
        {
            double up=(p-i);
            double down=i+1;

            ans*=up/down;
            i++;
        }

        while(j<s)
        {
            double up=(r-j);
            double down=j+1;

            ans/=up/down;
            j++;
        }

        cout<<setprecision(5)<<fixed<<ans<<endl;
    }
}
