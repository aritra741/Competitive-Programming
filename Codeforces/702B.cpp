#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<int,int>mp;
vector<int>v;

int main()
{
    int p= 1;
    v.push_back(1);

    for( int i=1;i<=30;i++ )
        p*= 2, v.push_back(p);

    int n;
    cin>>n;

    ll ans= 0;

    for( int i=0;i<n;i++ )
    {
        int q;
        cin>>q;

        for( int j=0;j<v.size();j++ )
            ans+= mp[ v[j]-q ];

        mp[q]++;
    }

    cout<< ans <<endl;
}
