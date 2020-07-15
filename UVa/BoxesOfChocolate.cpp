#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n,m;
        cin>>n>>m;

        ll ans=0;

        while(m--)
        {
            int k;
            cin>>k;

            ll temp=1;
            while(k--)
            {
                ll pt;
                cin>>pt;
                temp= (temp%n*pt%n)%n;
            }

            ans=(ans%n+temp%n)%n;
        }

        cout<< ans <<endl;
    }
}
