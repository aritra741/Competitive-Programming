#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;

    while( getline(cin,s) )
    {
        int carry[26], d[26];
        bool found[26];

        for(int i=0;i<26;i++)
            d[i]=i+1,carry[i]=0, found[i]=0;

        int len=s.size();

        for(int i=0;i<len;i++)
        {
            if(s[i]>='a' and s[i]<='z')
                {
                    found[s[i]-'a']=1;
                    if(s[i+1]=='+' and s[i+2]=='+')
                        carry[s[i]-'a']++, s[i+1]=' ', s[i+2]=' ';
                    else if(s[i+1]=='-' and s[i+2]=='-')
                        carry[s[i]-'a']--, s[i+1]=' ', s[i+2]=' ';
                    else if(i-2>=0 and s[i-1]=='-' and s[i-2]=='-')
                        d[s[i]-'a']--, s[i-1]=' ', s[i-2]=' ';
                    else if(s[i-1]=='+' and s[i-2]=='+')
                        d[s[i]-'a']++, s[i-1]=' ', s[i-2]=' ';
                }
        }

        bool sign=1;
        int tot=0;

        for(int i=0;i<len;i++)
        {
            if(sign and s[i]>='a' and s[i]<='z')
                tot+= d[s[i]-'a'];
            else if(!sign and s[i]>='a' and s[i]<='z')
                tot-= d[s[i]-'a'];
            else if(s[i]=='+')
                sign=1;
            else if(s[i]=='-')
                sign=0;
        }

        cout<<"Expression: "<<s<<endl;
        cout<<"    value = "<<tot<<endl;

        for(int i=0;i<26;i++)
            if(found[i])
                cout<<"    "<<(char)(i+'a')<<" = "<<d[i]+carry[i]<<endl;
    }
}
