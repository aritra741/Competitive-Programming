#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long prev=1000000009;
    bool flag=0;
    for(int i=0;i<n;i++)
    {
        long long p,q;
        cin>>p>>q;
        long long piv1=max(p,q);
        long long piv2=min(p,q);
        if(piv1<=prev)
        {
            prev=piv1;
        }
        else if(piv2<=prev)
        {
            prev=piv2;
        }
        else
            flag=1;

    }

    if(flag)
        cout<<"NO";
    else
        cout<<"YES";
}
