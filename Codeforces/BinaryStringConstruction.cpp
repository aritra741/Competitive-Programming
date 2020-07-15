#include <bits/stdc++.h>
using namespace std;
int main()
{
    int zer, one, alt;
    cin>>zer>>one>>alt;
    string s="";
    for(int i=0;i<zer;i++)
        s+="0";
    for(int i=0;i<one;i++)
        s+="1";
    bool flag=0;
    int len=zer+one;
    while(!flag)
    {
        next_permutation(s.begin(), s.end());
        int cnt=0;
        for(int i=0;i<len-1;i++)
            if(s[i]!=s[i+1])
                cnt++;
        if(cnt==alt)
            flag=1;
    }

    cout<<s;
}
