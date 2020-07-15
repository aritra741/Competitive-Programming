#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    bool flag=0;
    cin>>n;
    string s;
    cin>>s;
    int st=-1;
    int fn=-1;
    int len=s.length();
    char init=s[0];
    int cnt=0;
    for(int i=0; i<len-1; i++)
    {
        if(s[i]=='1' && s[i+1]=='1')
        {
            flag=1;
            break;
        }
        else
        {
            if(len>=3 && i!=len-2)
            {
                if(s[i]=='0' && s[i+1]=='0' && s[i+2]=='0')
                {
                    flag=1;
                    break;
                }
            }
            if(len>=2 && (i==0 || i==n-2))
            {
                if(s[i]=='0' && s[i+1]=='0')
                {
                    flag=1;
                    break;
                }

            }
        }
    }
    if(len==1 && s[0]=='0')
        flag=1;
    if(flag==1)
        cout<<"No";
    else
        cout<<"Yes";

}
