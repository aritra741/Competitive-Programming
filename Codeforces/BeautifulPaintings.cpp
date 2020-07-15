#include <bits/stdc++.h>
using namespace std;

map <int, int> mp;
map <int, int> ::iterator it;

int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        int p;
        cin>>p;
        mp[p]++;
    }

    int cnt=0;
    bool f=0;

    while(!f)
    {
        int t=0;
        for(it=mp.begin(); it!=mp.end(); it++)
        {


            if( it->second >= 1 )
            {
                    t++;
                mp[it->first]--;
            }


        }

        if(t)
            cnt+=t-1;
        else
            f=1;
    }


    cout<<cnt<<endl;
}
