#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long n,a;
    cin>>n;
    unsigned long long sum=0;
    unsigned long long MAX=0;
    for(long long i=0;i<n;i++)
    {
        cin>>a;
        sum+=a;
        MAX=max(MAX, a);

    }
    double semians=sum/((double)(n-1));
    unsigned long long ans=max((unsigned long long)ceil(semians), MAX);
    cout<<ans;
}
