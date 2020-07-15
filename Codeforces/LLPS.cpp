#include <bits/stdc++.h>
using namespace std;

int main()
{
    map <char, int> mp;
    map <char, int> ::iterator it;

    string s;
    cin>>s;

    int len= s.size();

    for(int i=0;i<len;i++)
    {
        mp[s[i]]++;
    }

    char mx= 0;

    for(it=mp.begin();it!=mp.end();it++)
    {
        mx= max( mx, it->first );
    }

    for(int i=0;i<mp[mx];i++)
    {
        cout<<(char)mx;
    }
}
