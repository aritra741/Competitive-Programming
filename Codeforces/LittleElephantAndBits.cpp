#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    bool flag=0;
    int len=s.length();
    for(int i=0; i<len; i++)
    {
        if(s[i]=='0')
        {
            flag=1;
            s.erase(i,1);
            break;
        }

    }
    if(!flag)
        s.erase(0,1);

cout<<s;
}
