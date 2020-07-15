#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b)
{
    if(a==0)
        return b;
    return gcd(b%a, a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll p,q,b;
    for(int i=0;i<n;i++)
    {
        cin>>p>>q>>b;
        ll a=min(p,q);
        ll c=max(p,q);
        ll g=gcd(a,c);
        p/=g;
        q/=g;
        if(q==1)
        {
            cout<<"Finite"<<endl;
            continue;
        }
        a=min(q,b);
        c=max(q,b);
        ll ans=gcd(a,c);
        while(ans!=1)
        {
            while(q%ans==0)
                q/=ans;
            ans=gcd(q,b);
        }
        if(q==1)
            cout<<"Finite"<<endl;
        else
            cout<<"Infinite"<<endl;
    }
}
