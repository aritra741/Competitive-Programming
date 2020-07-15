#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;

    while(cin>>s>>t)
    {
        int cnt=0;
        int len= t.size();
        int l= s.size();

        for(int i=0;i<len;i++)
        {
            if(s[cnt]==t[i])
                cnt++;
        }

        if(cnt==l)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}
