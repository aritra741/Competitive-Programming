#include <bits/stdc++.h>
#define ll long long
using namespace std;
map <ll, int> mp;
map <ll, int> ::iterator it;
map <ll, int> ::iterator it2;
int main()
{
    ll n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll num;
        cin>>num;
        mp[num]++;
    }

    int ans=0;

    for(it=mp.begin();it!=mp.end();it++)
    {
        bool found=0;
        for(int i=0;i<33;i++)
        {
            if(found)
                break;
            ll tot= pow(2, i);
            if(tot>=it->first){
            ll rem=tot-it->first;
            it2= mp.find(rem);
            if(it!=mp.end())
            {
                if(mp[rem]>=2 or (mp[rem]==1 && rem!=it->first))
                    found=1;
            }
            }

        }

        if(!found)
            ans+=it->second;
    }

    cout<<ans;
}
