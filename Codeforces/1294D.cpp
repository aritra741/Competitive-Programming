#include<bits/stdc++.h>
using namespace std;

int mp[400007];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,x;
    cin>>n>>x;

    int ans= 0;

    while(n--)
    {
        int p;
        cin>>p;

        mp[p%x]++;

        while( mp[ans%x] )
            mp[ans%x]--, ans++;

        cout<<ans<<'\n';
    }
}
