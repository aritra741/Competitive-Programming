#include<bits/stdc++.h>
using namespace std;

map<char,int>mp;
bool done[200007];

int main()
{
    string s,t;
    cin>>s>>t;

    for( int i=0; i<t.size(); i++ )
        mp[ t[i] ]++;

    int cc= 0, pp= 0;
    for( int i=0 ; i<s.size(); i++ )
    {
        if( mp[ s[i] ] )
            cc++, mp[ s[i] ]--, done[i]= 1;
    }

    for( int i=0; i<s.size(); i++ )
        if( !done[i] )
        {
            char c= s[i];

            if( isupper(c) )
                c= tolower(c);
            else
                c= toupper(c);
            if( mp[c] )
                pp++, mp[c]--;
        }

    cout<< cc <<" "<< pp <<endl;
}
