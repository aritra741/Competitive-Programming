#include<bits/stdc++.h>
using namespace std;

map<int,int>mp;
int arr[200007];

int main()
{
    int n;
    cin>>n;

    int ans= 0;
    int x= 1;

    for( int i=1;i<=n;i++ )
    {
        int p;
        cin>>p;

        arr[i]= p;

        mp[p]= max( mp[p], mp[p-1]+1);

        if( mp[p]>ans )
            ans=mp[p], x= p;
    }

    cout<<ans<<endl;

    vector<int>v;

    for( int i=n;i>=1;i-- )
        if( arr[i]==x )
            v.push_back(i), x--;

    reverse( v.begin(), v.end() );

    for( auto q: v )
        cout<<q<<" ";
}
