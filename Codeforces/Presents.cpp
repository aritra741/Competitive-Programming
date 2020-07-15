#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,temp;
    cin>>n;
    map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
        cin>>temp;
        mp[temp]=i;
    }
    for(int i=1;i<=n;i++)
        cout<<mp[i]<<" ";
}
