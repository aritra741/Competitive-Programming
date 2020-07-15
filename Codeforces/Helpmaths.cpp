#include <bits/stdc++.h>
using namespace std;
priority_queue <int, vector<int>, greater<int>> q;
int main()
{
    string s;
    cin>>s;
    stringstream ss;
    ss<<s;
    string t="";
    while(getline(ss,t,'+'))
        q.push(stoi(t));
    while(!q.empty())
    {
        if(q.size()!=1)
        cout<<q.top()<<'+';
        else cout<<q.top();
        q.pop();
    }
}
