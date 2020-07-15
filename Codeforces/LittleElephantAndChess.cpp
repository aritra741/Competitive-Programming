#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool flag=0;
    for(int i=0;i<8;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<7;j++)
        {
            if(s[j]==s[j+1])
                flag=1;
        }
    }
    if(flag)
        cout<<"NO";
    else
        cout<<"YES";
}
