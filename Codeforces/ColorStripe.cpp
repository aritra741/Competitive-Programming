#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    string s1="",s2="";
    if(k==2)
    {
        int alt=0,cnt1=0,cnt2=0;;
        for(int i=0;i<n;i++)
        {
            s1.push_back('A'+alt);
            s2.push_back('A'+!alt);
            alt=!alt;
        }

        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s[i])
                cnt1++;
            if(s2[i]!=s[i])
                cnt2++;
        }

        if(cnt1<cnt2)
        {
            cout<<cnt1<<endl<<s1;
            return 0;
        }
        if(cnt2<=cnt1)
        {
            cout<<cnt2<<endl<<s2;
            return 0;
        }
    }

    else
    {
        int cnt=0;
        for(int i=0;i<n-1;i++)
        {
            char c='A';
            if(s[i]==s[i+1])
            {
                cnt++;
                while(c==s[i] or c==s[i+2])
                    c++;
                s[i+1]=c;
            }

        }


        cout<<cnt<<endl<<s;
    }
}


