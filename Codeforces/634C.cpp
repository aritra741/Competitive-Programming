#include<bits/stdc++.h>
using namespace std;

string t="CODEFORCES";

int main()
{
    string s;
    cin>>s;

    if( s.size()<t.size() )
        return cout<<"NO\n", 0;
    if( s.size()==t.size() )
    {
        if( s==t )
            return cout<<"YES\n", 0;
        return cout<<"NO\n", 0;
    }

    int pref= 0, suff= 0;

    for( int i=0;i<s.size();i++ )
    {
        if( s[i]==t[i] )
            pref++;
        else
            break;
    }

    int j= t.size()-1;

    for( int i= s.size()-1;i>=0,j>=0;i--,j-- )
    {
        if( s[i]==t[j] )
            suff++;
        else
            break;
    }

    if( pref+suff>=t.size() )
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
