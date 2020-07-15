#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        int n,l;
        cin>>n>>l;

        int lim[n], req[n];

        int tot=0;

        for(int i=0;i<n;i++)
        {
            cin>>req[i];
            tot+=req[i];
        }

        bool flag=0;

        for(int i=0;i<n;i++)
        {
            cin>>lim[i];
            if(lim[i]<req[i])
                flag=1;
        }

        cout<<"Case "<<t<<": ";

        if(tot>l)
        {
            cout<<"No\n";
            continue;
        }

        if(flag)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
}
