#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll tot[200007];
int mxinarr[200007], mofarr[200007];

int main()
{
    int n;
    cin>>n;

    int idx= 0;
    ll mx= -1;
    ll totmx= -1, totsec= -1;
    bool chng= 0;

    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;

        ll sec= -1, fir= -1;
        mofarr[i]= m;

        while(m--)
        {
            ll p;
            cin>>p;

            if(p>fir)
                fir= p;
            else if(p>sec)
                sec= p;

            if(p>=mx)
                chng= 1;
        }

        mxinarr[i]= fir;

        if(chng)
        {
            chng= 0;

            if(fir>mx)
                mx= fir, idx= i, sec= totsec;
            else if(sec<totsec)
                idx= i, sec= totsec;
        }
    }

    ll ans= 0;

    for(int i=0;i<n;i++)
    {
        if(idx==i)
            continue;

        ll increase= mx-mxinarr[i];
        ll totinc= mofarr[i]*increase;
        ans+=totinc;

    }

    cout<<ans<<endl;
}
