#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    cin>>s>>t;

    if( s==t )
        return cout<<"YES\n", 0;
    if( s.size()!=t.size() )
        return cout<<"NO\n", 0;

    int f= 0;

    for( int i=0;i<s.size();i++ )
        if( s[i]=='1' and !f )
            f++;
    for( int i=0;i<s.size();i++ )
        if( t[i]=='1' and f==1 )
            f++;

    if( f>=2 )
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
