#include <bits/stdc++.h>
#define ll long long
#define p 31
#define mod 1000000007
#define mx 200007
using namespace std;

ll h1[mx], h2[mx];

int main()
{
    string s,t;
    cin>>s;
    cin>>t;

    n= s.size();

    for( int i=0;i<s.size();i++ )
    {
        cnt[i+1][ s[i]-'a' ]++;

        for( int j=0;j<26;j++ )
            cnt[i+1][j]+= cnt[i][j];
    }
    for( int i=0;i<t.size();i++ )
    {
        cnt1[i+1][ t[i]-'a' ]++;

        for( int j=0;j<26;j++ )
            cnt1[i+1][j]+= cnt1[i][j];
    }

}
