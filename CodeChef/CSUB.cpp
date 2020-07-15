#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int p;
        cin>>p;
        string s;
        cin>>s;
        unsigned long long len=s.length();
        unsigned long long cnt=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='1')
                cnt++;
        }
        unsigned long long ans=(cnt*(cnt+1))/2;
        cout<<ans<<endl;
    }
}
