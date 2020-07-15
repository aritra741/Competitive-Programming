#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    if(s[0]=='-')
    {
        if(s.length()==2)
            cout<<0;
        else
        {
            if(s[s.length()-1]>=s[s.length()-2])
            {
                s.erase(s.length()-1,1);
                if(s[1]=='0')
                    s.erase(0,1);
                cout<<s;

            }
            else
            {
                s.erase(s.length()-2,1);
                if(s[1]=='0')
                    s.erase(0,1);
                cout<<s;
            }
        }
    }
    else
        cout<<s;
}

