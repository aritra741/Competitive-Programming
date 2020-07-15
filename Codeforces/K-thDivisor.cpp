#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main()
{
    ull n,k,i,cnt=0,flag=0;

    cin>>n>>k;

    ull sq=sqrt(n);
    vector <ull> num;

    for(i=1; i<=sq; i++)
    {
        if(n%i==0)
        {
            num.push_back(i);
            cnt++;
            if(i==sq && i*i==n)
            {
                num.push_back(i);
                flag=cnt;

            }
        }

    }

    if(k<=cnt)
        cout<<num[k-1];

    else if(k<=cnt*2)
    {
        if(k==flag)
            k--;
        if(flag!=0 && k<=cnt*2-1)
            cout<<n/num[cnt*2-k-1];
        else if(flag!=0)
            cout<<"-1";
        else
            cout<<n/num[cnt*2-k];
    }
    else
        cout<<"-1";
}
