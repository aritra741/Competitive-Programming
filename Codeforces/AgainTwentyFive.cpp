#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull power(ull n)
{
    n=100;
    ull ans=1;
    ull x=5;
    while(n>0)
    {
        if(n&1)
            ans=((ans%100)*(x%100))%100;
        n=n>>1;
        x=x*x%100;

    }
    return ans;
}

int main()
{
    ull n;
    cin>>n;
    ull ans=power(n);
    cout<<ans;
}
