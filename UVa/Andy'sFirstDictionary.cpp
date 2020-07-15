#include <bits/stdc++.h>
using namespace std;
set<string> dis;
set<string> ::iterator it;

bool normal(char c)
{
    return  ( c>='a' && c<='z' );
}

int main()
{
    string s;
    string t="";
    while(getline(cin,s))
    {
        int len=s.length();

        for(int i=0;i<len;i++)
        {
            char c=tolower(s[i]);
            if(normal(c))
                t.insert(t.end(), 1 , c);

            else if(s[i]=='-' && i!=len-1)
                    t.insert(t.end(), 1 , s[i]);
            else if(t!="" && s[i]!='-')
            {
                dis.insert(t);
                t="";
            }
        }
        if(t!="" && s[len-1]!='-')
            {
                dis.insert(t);
                t="";
            }



    }
    for(it=dis.begin();it!=dis.end();it++)
            cout<<*it<<endl;
}
