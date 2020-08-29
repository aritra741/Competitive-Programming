#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll gcd(ll p, ll q)
{
    ll a=max(p,q);
    ll b= min(p,q);

    if(b==0)
        return a;
    gcd(a%b, b);
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        getchar();
        int n;
        cin>>n;

        int arr[n];
        int negs=0;
        ll numer= 0;

        for(int i=0;i<n;i++)
            {
                cin>>arr[i];
                if(arr[i]<0)
                    negs++;
                numer+= abs(arr[i]);
            }

        if(negs==n)
        {
            cout<<"Case "<<t<<": inf"<<endl;
            continue;
        }

        numer*=100000;
        ll denom=100000*(n-negs);
        ll g= gcd(numer, denom);

        cout<<"Case "<<t<<": "<<numer/g<<"/"<<denom/g<<endl;


    }
}
