#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,s1;
    cin>>s;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='.')
            s1.push_back('0');
        else
        {
            if(s[i+1]=='.')
            {
                s1.push_back('1');
                i++;
            }
            else {
                s1.push_back('2');
                i++;
            }
        }
    }
    cout<<s1;
}
