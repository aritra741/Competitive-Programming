#include <bits/stdc++.h>
using namespace std;

string s;

int d[200007];

int recur(int pos)
{
   // cout<<pos<<endl;
    int len=s.length();
    if(pos==len)
        return 0;
    if(d[pos]!=-1)
        return d[pos];
    int ans=0,ans1=0,ans2=0;
    int sum=0;
    for(int i=pos;i<len;i++)
    {
        sum+=(s[i]-'0');
        sum%=3;

        if(sum==0)
        {
            ans1=max(ans, 1+recur(i+1));
            ans2=max(ans, recur(i+1));
            break;
        }
        else
            ans= max(ans, recur(i+1));
    }
    ans=max(ans, max(ans1, ans2));
    d[pos]=ans;
    return d[pos];
}

int main()
{
    memset(d, -1, sizeof(d));
    cin>>s;
    cout<<recur(0);

}
