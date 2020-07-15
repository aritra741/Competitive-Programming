#include<bits/stdc++.h>
#define pii pair<char,char>
#define ll long long
using namespace std;

map<char,ll>mp, mp2;
map<pii, ll>oc;

int main()
{
    string s;
    cin>>s;

    ll ans= 1;

    for( int i=0;i<s.size();i++ )
    {
        mp[ s[i] ]++;

        ans= max( ans, mp[ s[i] ] );

        for( char c='a';c<='z';c++ )
            if( c!=s[i] )
            {
                oc[ pii( c,s[i] ) ]+= mp[c];

                ans= max( ans, oc[ pii(c,s[i]) ] );
            }

        oc[ pii( s[i], s[i] ) ]+= mp[ s[i] ]-1;

        ans= max( ans, oc[ pii( s[i], s[i] ) ] );
    }

    cout<< ans <<endl;
}

