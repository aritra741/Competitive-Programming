#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int power=n/2;
    long long ans=0;
    for(int i=0;i<=10;i++)
    {
        long long temp=1;
        for(int j=0;j<power;j++)
            temp*=i;
        ans+=temp;
    }
    cout<<ans;
}
