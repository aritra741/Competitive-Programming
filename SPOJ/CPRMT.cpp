#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;

    while( cin>>s and cin>>t )
    {
        sort( s.begin(), s.end() );
        sort( t.begin(), t.end() );

        vector<int> cnt1( 30,0 ), cnt2( 30, 0 );

        for( int i=0;i<s.size();i++ )
            cnt1[ s[i]-'a' ]++;
        for( int i=0;i<t.size();i++ )
            cnt2[ t[i]-'a' ]++;

        string ans;

        for( int i=0;i<26;i++ )
            for( int j=0;j<min( cnt1[i], cnt2[i] );j++ )
                ans+= (char)( i+'a' );

        cout<< ans <<endl;
    }
}
