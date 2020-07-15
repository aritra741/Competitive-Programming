#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    bool flag=0;
    ll n;
    cin>>n;
    ll l,r;
    ll mn=1000000009,mx=-100000009;
    ll ans=-1;
    bool first=1;
    ll fl,fr;
    for(int i=0;i<n;i++)
    {
        cin>>l>>r;
        if(first)
        {
            fl=l,fr=r;
            first=0;
        }

        else{
                if(mn>l || mx<r)
                flag=0;
                if(l<=mn && r>=mx)
        {
            ans=i+1;
            flag=1;
        }


        }
        mn=min(mn, l);
        mx=max(mx, r);



    }



    if(flag)
        cout<<ans;
    else if(mn==fl && mx==fr)
        cout<<"1";
    else
        cout<<"-1";
}
