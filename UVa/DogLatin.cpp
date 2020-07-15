#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(getline(cin,s))
    {
        int flg=-1;
        int len=s.length();
        string t="";
        for(int i=0;i<len;i++)
        {
            if(s[i]<65 || (s[i]>90 && s[i]<97) || s[i]>122)
            {
                if(flg==-1)
                    cout<<s[i];
                else
                {
                    if(t[0]=='a' || t[0]=='e' || t[0]=='i' || t[0]=='o'|| t[0]=='u' ||t[0]=='A' ||t[0]=='E' ||t[0]=='I' ||t[0]=='O' ||t[0]=='U' )
                    {
                        for(int j=0;j<=flg;j++)
                        cout<<t[j];
                        cout<<"ay";
                        flg=-1;
                        t="";
                        cout<<s[i];
                    }
                    else{
                    for(int j=1;j<=flg;j++)
                        cout<<t[j];
                        cout<<t[0]<<"ay";
                        cout<<s[i];
                    flg=-1;
                    t="";
                }
            }
            }
            else
            {
                flg++;
                t+=s[i];
            }
            if(((s[i]>=65 && s[i]<=90) && i==len-1) || ((s[i]>=97 &&s[i]<=122) && i==len-1))
                {
                    if(t[0]=='a' || t[0]=='e' || t[0]=='i' || t[0]=='o'|| t[0]=='u' ||t[0]=='A' ||t[0]=='E' ||t[0]=='I' ||t[0]=='O' ||t[0]=='U' )
                    {
                        for(int j=0;j<=flg;j++)
                        cout<<t[j];
                        cout<<"ay";
                        flg=-1;
                        t="";
                    }
                    else{
                    for(int j=1;j<=flg;j++)
                        cout<<t[j];
                        cout<<t[0]<<"ay";

                    flg=-1;
                    t="";
                }
                }
        }
        cout<<endl;
    }
}
