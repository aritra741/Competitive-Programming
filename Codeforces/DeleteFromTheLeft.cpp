#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s;
    cin>>t;
    string ss1,ss2;
    if(t.length()>s.length())
        {
            ss1=t;
            ss2=s;
        }
    else
    {
        ss1=s;
        ss2=t;
    }

    string ss3=ss1.substr(ss1.length()-ss2.length(), ss2.length());

    int len=ss2.length();
    int idx=-1;
    for(int i=0;i<len;i++)
    {
        if(ss3[i]!=ss2[i])
            idx=i;
    }

    int res=ss1.length()-ss2.length();
    if(idx!=-1)
        res+=(idx+1)*2;
    cout<<res;
}
