#include <bits/stdc++.h>
#define debug(s) cout<<s<<endl;
using namespace std;
int main()
{
    double k,d,t,dif,eq,ans=0;
    double sum=0;
    cin>>k>>d>>t;
    if((int)k%(int)d==0)
        cout<<t;
    else
    {
        for(int i=1;;i++)
        {
            if(i*d>k)
            {d=i*d;
            break;}
        }
        d-=k;
        double off=k/t;
        double on=d/(2*t);
     double sum=(k/t)+(d/(2*t));
     ans=floor(1/sum)*(k+d);
     dif=1-(sum*ceil(1.0/sum));
     if(off<=dif)
     {
         ans+=k;
        dif=dif-off;
        if(on<=dif)
     {
         ans+=d;
        dif=dif-on;
     }
    else if(on>dif)
    {
        double temp=dif*2*t;
        ans+=temp;

    }

     }
    else if(off>dif)
    {
        double temp=dif*t;
        ans+=temp;

    }


cout<<setprecision(20)<<fixed<<ans;
    }

}
