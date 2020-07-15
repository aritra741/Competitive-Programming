#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
map<string, int> ::iterator it;

int main()
{
    int len;
    cin>>len;
    string s;
    cin>>s;

    for(int i=0;i<len-1;i++)
    {
        string str= s.substr(i, 2);
        mp[str]++;
    }

    string ans;
    int mx=-1;

    for(it=mp.begin(); it!= mp.end(); it++)
    {
        if(it->second > mx)
        {
            mx=it->second;
            ans=it->first;
        }
    }

    cout<<ans<<endl;




}
