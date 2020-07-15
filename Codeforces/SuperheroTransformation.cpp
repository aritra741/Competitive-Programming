#include <bits/stdc++.h>
using namespace std;

int isVowel( char c )
{
    if( c=='a' )
        return 1;
    if( c=='e' )
        return 1;
    if( c=='i' )
        return 1;
    if( c=='o' )
        return 1;
    if( c=='u' )
        return 1;
    return -1;

}

int main()
{
    string s,t;
    cin>>s>>t;

    bool valid= 1;
    if( s.size()!=t.size() )
        cout<<"No";
    else
    {
        for(int i=0;i<s.size();i++)
            if( isVowel( s[i] )*isVowel( t[i] )<0 )
                valid= 0;

    if( valid )
        cout<<"Yes";
    else
        cout<<"No";
    }
}
