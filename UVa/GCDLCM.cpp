#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if(a==0)
        return b;
    return gcd(b%a, a);
}

int main()
{
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
    int a,b;
    cin>>a>>b;
    int ans=gcd(a,b);
    if(ans==a)
        cout<<a<<" "<<b<<endl;
    else
        cout<<-1<<endl;
}
}
