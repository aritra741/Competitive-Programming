#include <bits/stdc++.h>
using namespace std;
int main()
{
    map <string, string> mp;
    int n,m;
    cin>>n>>m;
    string s1,s2;
    for(int i=0; i<m; i++)
    {
        cin>>s1>>s2;
        if(s1.length()<=s2.length())
        {
            mp[s1]=s1;
            mp[s2]=s1;
        }
        else
        {
            mp[s1]=s2;
            mp[s2]=s1;
        }
    }
    string s[n];
    for(int i=0; i<n; i++)
        cin>>s[i];
    for(int i=0; i<n; i++)
        cout<<mp[s[i]]<<" ";

}
