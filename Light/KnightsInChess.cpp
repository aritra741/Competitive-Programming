#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc,temp;cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        int m,n,ans;
        cin>>m>>n;
        int mult=m*n;
        if(m==1 || n==1)
            ans=mult;
        else if(m!=2 && n!=2)
            {
                if(mult%2==0)
                    ans=mult/2;
                else ans=mult/2+1;
            }
        else
        {
            if(m==2)
                temp=n;
            else temp=m;
            if(temp%4==0)
                ans=temp;
            else if(temp%4==2)
                ans=temp+2;
            else ans=temp+1;

        }
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
}
