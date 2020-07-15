#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++)
    {
        int k;
        cin>>k;
        map<char, int> mp;
        for(int j=0;j<k;j++)
        {
            char ch;
            int a;
            cin>>ch>>a;
            mp[ch]=a;
        }
        int line;
        cin>>line;
        double sum=0;
        line++;
        while(line--)
        {
            string s;
            getline(cin, s);
            int len=s.length();
            for(int p=0;p<len;p++)
                sum+=mp[s[p]];

        }
        cout<<setprecision(2)<<fixed<<sum/100<<"$"<<endl;
    }
}

