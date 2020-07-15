#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b;
    cin>>a>>b;
    long long mn=min(a,b);
    long long mx=max(a,b);
    long long cnt=0;
    while(mn>0 && mx>0)
    {
        cnt+=mx/mn;
        long long a=mx%mn;
        long long b=mn;
        mn=a;
        mx=b;

    }

    cout<<cnt;
}
