#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<int,int>mp;

int main()
{
    int n,x;
    cin>>n>>x;

    ll ans= 0;

    for( int i=0;i<n;i++ )
    {
        int p;
        cin>>p;

        int q= p^x;

        ans+= mp[q];

        mp[p]++;
    }

    cout<< ans <<endl;
}
