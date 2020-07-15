#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int ans=a;
    int rem=0;
    while(a>=b)
    {
        rem=a%b;
        a/=b;

        ans+=a;
        a+=rem;

    }
    cout<<ans;
}
