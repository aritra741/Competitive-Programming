#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<int, int> mp;
map<int, int> ::iterator it;

int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        int n;
        cin>>n;

        for(int i=0;i<n;i++)
        {
            int p;
            cin>>p;
            mp[p+1]++;
        }

        ll tot= 0;

        for(it=mp.begin();it!=mp.end();it++)
        {
            ll cnt= ceil( (double)(it->second)/(it->first) );
            cnt*= (it->first);
            tot+=cnt;
        }

        cout<<"Case "<<t<<": "<<tot<<endl;

        mp.clear();
    }
}
