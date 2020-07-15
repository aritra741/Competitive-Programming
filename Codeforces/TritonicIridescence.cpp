#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int flag=0;
    int len=s.length();
    int cnt=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='?')
            {
                cnt++;
                if(i!=len-1)
                    if(s[i+1]=='?')
                        flag=2;
                if(i==0)
                    if(i+2<len)
                        if(s[i+2]=='?')
                            flag=2;
                                }
        if(i!=len-1)if(s[i]==s[i+1] && s[i]!='?')
        {
           // cout<<s[i]<<" "<<s[i+1]<<endl;
            flag=1;
            break;

        }
        if(i!=0 && s[i]=='?' && i!=len-1)
        {
            if(s[i-1]!=s[i+1] && s[i-1]!='?' && s[i+1]!='?')
            {
                //cout<<s[i-1]<<" "<<s[i+1]<<endl;
                if(flag!=2)
                {
                   // cout<<s[i-1]<<" "<<s[i+1]<<endl;
                    flag=1;

                }


            }
            if(s[i-1]==s[i+1] && s[i-1]!='?' && s[i+1]!='?')
            {
                //cout<<s[i-1]<<" "<<s[i+1]<<endl;
                flag=2;


            }
        }

    }
    if(len==1 && s[0]=='?')
        cout<<"YES";
    else
    {
    if(flag!=1 && cnt>0)
    cout<<"YES";
    else cout<<"NO";
    }
}
