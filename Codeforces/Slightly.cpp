#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,k;
    cin>>n>>k;
    for(long long i=1;i<n-k;i++)
        cout<<i<<" ";
    for(long long i=n;i>=n-k;i--)
        cout<<i<<" ";
}
