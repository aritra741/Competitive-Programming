#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map <int, int> mp;
    map <int, int> ::iterator it;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        mp[t]++;
    }

    int mx=-100;

    for(it=mp.begin();it!=mp.end();it++)
    {
        mx=max(mx, it->second);
    }

    cout<<mx<<endl;


}
