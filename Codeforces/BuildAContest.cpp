#include <bits/stdc++.h>
using namespace std;

map<int,int> mp;
map<int,int> ::iterator it;

int main()
{
    int n,m;
    cin>>n>>m;

    int tot= 0;

    for(int i=0; i<m; i++)
    {
        int p;
        cin>>p;

        mp[p]++;

        if(mp[p]==1)
            tot++;

        if(tot==n)
        {
            cout<<"1";
            for(it=mp.begin(); it!=mp.end(); it++)
            {
                it->second= it->second-1;

                if(it->second==0)
                    tot--;
            }
        }

        else
            cout<<"0";
    }
}
