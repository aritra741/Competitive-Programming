#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n;
    cin>>n;

    int len= log10(n) + 1;
    ll high= sqrt(n);

    if(high*high==n)
    {
        cout<<"0"<<endl;
        return 0;
    }

    bool flag=0;

    for(ll i=high; i>=1; i--)
    {
        if(flag)
            break;

        bool cont=0;
        int cnt=0;

        ll t= i*i;
        int l = log10(t) + 1;
        ll d= n;

        for(int j=0; j<len; j++)
        {
            if(cont)
            {
                t/=10;
                cont=0;
            }
            ll p=d%10;
            d/=10;

            if(t%10==p)
            {
                cont=1;
                cnt++;
            }

            if(cnt==l)
            {
                flag=1;
                cout<<len-l<<endl;
                break;
            }
        }


    }

    if(!flag)
        cout<<"-1"<<endl;



}
