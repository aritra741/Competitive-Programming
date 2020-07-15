#include <bits/stdc++.h>
using namespace std;

int ret(int num)
{
    int ans= 0;

    while(num>0)
    {
        ans+=num%10;
        num/=10;
    }

    return ans;
}

int main()
{
    int k;
    cin>>k;

    int i, cnt=0;

    for(i=10;i<100000007;i++)
    {
        if(ret(i)==10)
            cnt++;
        if(cnt==k)
            break;
    }

    cout<<i<<endl;
}
