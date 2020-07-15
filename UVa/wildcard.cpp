#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++)
    {
        bool flag=0;
        string s,s1;
        cin>>s;
        cin>>s1;
        int len=s.length();
        for(int j=0;j<len;j++)
            {if(s[j]==s1[j] || s[j]=='?' || s1[j]=='?')
                        continue;
                    else
                    {
                        flag=1;
                        break;
                    }

        }
        if(flag==1)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
}
