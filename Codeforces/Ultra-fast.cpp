#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,s1,s2;
    cin>>s1;
    cin>>s2;
    for(int i=0; i<s1.length(); i++)
    {
        if(s1[i]==s2[i])
            s.push_back('0');
        else
            s.push_back('1');

    }
    cout<<s;
}
