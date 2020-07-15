#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,m,t;
    cin>>n>>m>>t;

    if(n+m<t)
        cout<<"0"<<endl;
    else
    {
        ll ans=0;
        for(int i=4;i<=n;i++)
        {
            if(t-i<=m and t-i>=1)
            {
                ll t1=1;
                int p=i;
                if(n-p<p)
                    p=n-p;
                for(int j=0;j<p;j++)
                {
                   // cout<<"yes"<<endl;
                    t1*= (n-j);
                    t1/=(j+1);
                }
                ll t2=1;
                int k=t-i;
                if(k>m-k)
                    k=m-k;
                for(int j=0;j<k;j++)
                {
                    t2*=(m-j);
                    t2/=(j+1);
                }

                ans+= (t1*t2);
            }
        }

        cout<<ans<<endl;

    }
}
