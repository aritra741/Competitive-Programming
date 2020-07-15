#include <bits/stdc++.h>
using namespace std;
priority_queue <int> q;
vector <int> v;
map <char,int> mp;
int main()
{
    int ans=0;
    string s;
    cin>>s;
    int n;
    cin>>n;
    for(char i='a';i<='z';i++)
    {
        cin>>mp[i];
        q.push(mp[i]);
    }
    int top=q.top();
//    v.push_back(q.top());
    for(int i=0;i<s.length();i++)
        v.push_back(mp[s[i]]);
//    sort(v.begin(), v.end(), greater<>());
//    cout<<v[0]<<endl;
    for(int i=1;i<=s.length();i++)
    {

        ans=ans+(i*v[i-1]);
    }
    for(int i=s.length()+1;i<=s.length()+n;i++)
    {
             ans=ans+top*i;
    }


cout<<ans;
}
