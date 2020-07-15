#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int len=s.length();
    bool flag=0;
    for(int i=0;i<len-1;i++)
    {
        if(s[i]!='a' and s[i]!='e' and s[i]!='i' and s[i]!='o' and s[i]!='u' and s[i+1]!='a' and s[i+1]!='e' and s[i+1]!='i' and s[i+1]!='o' and s[i+1]!='u' and s[i]!='n')
            flag=1;
    }
    if(!flag)
    {
        if(s[len-1]!='a' and s[len-1]!='e' and s[len-1]!='i' and s[len-1]!='o' and s[len-1]!='u' and s[len-1]!='n')
           flag=1;
    }

    if(flag)
        cout<<"NO";
    else
        cout<<"YES";
}
