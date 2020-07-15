#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n==2)
        cout<<10;
    else if(n==4){
    int power=n/2;
    long long ans=0;
    for(int i=0;i<=10;i++)
    {
        long long temp=1;
        for(int j=0;j<power;j++)
            temp*=i;
        ans+=temp;
    }
    for(int i=0;i<10;i++)
    {
        long long temp=1;
        for(int j=0;j<power;j++)
            temp*=i;
        ans+=temp;
    }
    cout<<ans;
    }
    else if(n==6)
    {
        long long ans=1;
        for(int i=1;i<=18;i++)
        {
            ans+=(i*3)*(i*3);

        }
        for(int i=1;i<10;i++)
        {
            ans+=(i*3)*(i*3);

        }
        cout<<ans;
    }
}
