#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<string,int>mp;
string s[1507];

char get( char a, char b )
{
    if( a=='S' )
    {
        if( b=='T' )
            return 'E';
        if( b=='E' )
            return 'T';
        return 'S';
    }

    else if( a=='E' )
    {
        if( b=='S' )
            return 'T';
        if( b=='T' )
            return 'S';
        return 'E';
    }

    if( b=='S' )
        return 'E';
    if( b=='E' )
        return 'S';
    return 'T';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    for( int i=0; i<n; i++ )
        cin>>s[i], mp[ s[i] ]++;

    ll ans= 0;

    for( int i=0; i<n; i++ )
        for( int j=i+1; j<n; j++ )
        {
            string t;

            for( int l=0;l<k;l++ )
                t.push_back( get(s[i][l],s[j][l]) );

            ans+= mp[t];
        }

    cout<< ans/3 <<"\n";
}
