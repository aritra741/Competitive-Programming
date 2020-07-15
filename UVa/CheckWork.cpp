#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int cnt=0;
    while(getline(cin, s))
    {
        if(s=="")
            break;
        int len=s.length();
        if(s[len-1]=='?')
            continue;
        string s1="",s2="",s3="";
        int a=0,b=0,c=0;
        int i=0;
        for(; i<len; i++)
        {
            if(s[i]!='-' && s[i]!='+')
                s1[i]=s[i];
            else
                break;
        }
        char sign=s[i];

        s1[i]=0;
        a=stoi(s1);
        int j=0;
        for(; i<len; i++)
        {
            if(s[i]!='=')
            {if(s[i]!='-' && s[i]!='+')
                s2[j++]=s[i];}
            else
                break;
        }
        s2[j]=0;
        j=0;
        i++;

        for(; i<len; i++)
                s3[j++]=s[i];


        b=stoi(s2);
        s3[j]=0;
        c=stoi(s3);

        if(sign=='+')
        {
            if(c==a+b)
                cnt++;
        }
        else
        {
            if(c==a-b)
                cnt++;

        }
        s="";
        s1="",s2="",s3="";
    }
cout<<cnt<<endl;
}
