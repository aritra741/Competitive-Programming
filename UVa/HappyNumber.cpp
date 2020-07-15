#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n;
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        scanf("%lld", &n);
        ll temp=n;
        ll fin= 0;

        if(n<=9)
            n=n*n;

        while(n>=10)
        {
            fin=0;
            while(n>0)
            {
                ll p= n%10;
                fin+= p*p;
                n/=10;
            }

            n=fin;
        }

        if(n==1)
            printf("Case #%d: %lld is a Happy number.\n", t, temp);
        else
            printf("Case #%d: %lld is an Unhappy number.\n", t, temp);
    }


}
