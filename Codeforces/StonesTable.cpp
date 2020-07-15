#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cnt=0;
    int n;cin>>n;
    string s;cin>>s;
    for(int i=0;i<s.length()-1;i++)
        if(s[i]==s[i+1])
            cnt++;
    cout<<cnt;
}
