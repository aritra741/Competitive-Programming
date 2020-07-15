#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int len=s.length();
    for(int i=0;i<len;i++)
        if(s[i]=='r')
            printf("%d\n",i+1);
    for(int i=len-1;i>=0;i--)
        if(s[i]=='l')
            printf("%d\n",i+1);
}
