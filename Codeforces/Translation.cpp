#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,s1;
    cin>>s;
    cin>>s1;
    bool flag=0;
    int len=s1.length();
    if(s.length()==s1.length())
        {for(int i=0;i<s.length();i++)
            if(s[i]!=s1[len-1-i])
            {
                flag=1;
                break;
            }

    if(!flag)
        cout<<"YES";
    else cout<<"NO";}
    else cout<<"NO";
}
