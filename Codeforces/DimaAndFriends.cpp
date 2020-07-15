#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    bool num[511];
    int sum=0,cnt=0;
    memset(num, 0, sizeof(num));
    for(int i=1;i<=510;i+=(n+1))
    {
        num[i]=1;

    }
    int temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        sum+=temp;
    }
    for(int i=sum+1;i<=sum+5;i++)
    {
        if(num[i]==0)
            cnt++;
    }
    cout<<cnt;
}
