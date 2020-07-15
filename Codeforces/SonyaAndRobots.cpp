#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;
set<int> st;
bool vis[100007];

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            mp[arr[i]]++;
            st.insert(arr[i]);
        }
    int distinct=st.size();
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        int x=arr[i];
        if(mp[x]==1)
            distinct--;
        else
            mp[x]--;
        if(!vis[x])
        {
            vis[x]=1;
            ans+=distinct;
        }
    }

    cout<<ans<<endl;

}
