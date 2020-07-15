#include <bits/stdc++.h>
using namespace std;
int main()
{
    int len;
    string s,t;
    cin>>len;
    cin>>s;
    cin>>t;

    int tot=0;

    for(int i=0;i<len;i++)
    {
        if(s[i]!=t[i])
        {
            if(i!=len-1 and s[i+1]!=t[i+1] and s[i]==t[i+1] and s[i+1]==t[i])
                i++;
            tot++;
        }
    }

    cout << tot << endl;
}
