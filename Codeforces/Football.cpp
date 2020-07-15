#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    bool flag=0;
    cin>>s;
    int len=s.length();
    int cnt=0;
    char point=s[0];
    for(int i=0;i<len;i++)
    {


        if(s[i]==point)
            cnt++;
        else
        {
            point=s[i];
            cnt=1;
        }
        if(cnt==7)
        {
            cout<<"YES";
            return 0;
        }
    }
        cout<<"NO";
}
