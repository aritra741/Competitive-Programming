#include<bits/stdc++.h>
#define pii pair<char,char>
using namespace std;

map<pii,int>mp;

int main()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    int ans= 0;

    for( int i=1; i<n; i++ )
        mp[ pii( s[i], s[i-1] ) ]++, ans= max( ans, mp[ pii( s[i], s[i-1] ) ] );

    for( auto x: mp )
        if( x.second==ans )
        {
            cout<<x.first.second<<x.first.first<<endl;
            break;
        }
}
