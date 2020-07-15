#include <bits/stdc++.h>
using namespace std;

map<char,char> mp;

int main()
{
    string s,t;
    cin>>s>>t;

    for(int i=0;i<s.size();i++)
        mp[ s[i] ]= t[i];

    string ss;
    cin>>ss;

    for(int i=0;i<ss.size();i++)
    {
        if(ss[i]>='0' and ss[i]<='9')
        {
            cout<< ss[i];
            continue;
        }

        char c= ss[i];
        char C= tolower(c);
        c= mp[C];

        if( ss[i]>='A' and ss[i]<='Z' )
            c=toupper(c);

        cout<< c;
    }

}
