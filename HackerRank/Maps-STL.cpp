#include <bits/stdc++.h>
#define ll long long
using namespace std;

map <string, ll> mp;

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            string x;
            int y;
            cin>>x>>y;
            mp[x]+=y;
        }

        else if(type==2)
        {
            string x;
            cin>>x;
            mp[x]=0;
        }

        else
        {
            string x;
            cin>>x;
            cout<<mp[x]<<endl;
        }
    }
}
