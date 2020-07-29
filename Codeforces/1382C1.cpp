#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;

        string s,t;
        cin>>s;
        cin>>t;

        vector<int>vv;

        int x= s[0]-'0';

        for( int i=0;i<n-1;i++ )
            if( s[i]!=s[i+1] )
                x^= 1, vv.push_back(i+1);
        for( int i=n-1;i>=0;i-- )
            if( t[i]-'0'!=x )
                vv.push_back(i+1), x^= 1;

        cout<<vv.size()<<" ";

        for( auto x: vv )
            cout<<x<<" ";
        cout<<"\n";
    }
}
