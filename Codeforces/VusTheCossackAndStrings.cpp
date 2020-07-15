#include <bits/stdc++.h>
using namespace std;

int ans;

int main()
{
    string s,t;
    cin>>s>>t;

    int one= 0, zer= 0, o= 0, z= 0;

    for( int i=0;i<t.size();i++ )
        (t[i]=='0')?zer++:one++;

    for( int i=0;i<t.size();i++ )
        (s[i]=='0')?z++:o++;

    if( (one&1 and o&1) or ( !(one&1) and !(o&1) ) )
        ans++;

    for( int i=t.size();i<s.size();i++ )
    {
        (s[i-t.size()]=='0')?z--:o--;
        (s[i]=='0')?z++:o++;

        if( (one&1 and o&1) or ( !(one&1) and !(o&1) ) )
            ans++;
    }

    cout<< ans <<endl;
}
