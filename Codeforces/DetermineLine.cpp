#include <bits/stdc++.h>
using namespace std;

map<int,int> mp;
vector<int> ans;

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int r;
        cin>>r;

        while(r--)
        {
            int p;
            cin>>p;
            mp[p]++;

            if(mp[p]==n)
                ans.push_back(p);
        }
    }

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}
