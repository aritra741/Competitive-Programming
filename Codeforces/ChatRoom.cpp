#include <bits/stdc++.h>
using namespace std;
int main()
{
    string org="hello";
    string s;
    cin>>s;
    int cnt=0;
    int len=s.length();
    if(len<5)
        cout<<"NO";
    else
    {
    for(int i=0;i<len;i++)
    {
        if(s[i]==org[cnt])
            cnt++;
    }
    if(cnt==5)
        cout<<"YES";
    else
        cout<<"NO";

    }
}
