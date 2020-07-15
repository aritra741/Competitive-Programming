#include <bits/stdc++.h>
using namespace std;

map <string,string> mp;

int main()
{
    int n,m;
    string s,t;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>s>>t;
        mp[t]=s;
    }
    for(int i=0;i<m;i++)
    {
            cin>>s>>t;
            string temp=t;
            temp.erase(t.length()-1, 1);
            cout<<s<<" "<<t<<" #"<<mp[temp]<<endl;
    }
}
