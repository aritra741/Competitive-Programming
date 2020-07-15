#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt0=0,cnt1=0;
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        if(s[i]=='0')
            cnt0++;
        else cnt1++;
    }
    if(cnt1>0)
        cout<<1;
    for(int i=0;i<cnt0;i++)
        cout<<0;
}
