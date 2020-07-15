#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main()
{
    ull k,n,s,p;
    cin>>k>>n>>s>>p;
    ull pap=ceil( (double)n/s )*k;
    ull ans=ceil( (double)pap/p );
    cout<<ans;
}
