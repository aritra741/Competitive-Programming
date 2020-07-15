#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull power(ull n, ull p)
{
    if(p==0)
        return 1;
    if(p==1)
        return n%10;
    ull ans=1;
    while(p>0){
    if(p & 1)
    ans=(ans*n)%10;
    p=p>>1;
    n=(n*n)%10;
    }
    return ans;
}

int main()
{
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        ull a,b;
        cin>>a>>b;
        ull ans=power(a,b);
        cout<<ans<<endl;
    }
}
