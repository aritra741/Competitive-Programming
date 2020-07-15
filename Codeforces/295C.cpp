#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin>>tc;

    while(tc--)
    {
        string s,t;
        cin>>s;
        cin>>t;

        vector<int>v[27];

        for( int i=0;i<s.size();i++ )
            v[s[i]-'a'].push_back( i );

        bool f= 1;
        int ans= 1, now= -1;

        for( int i=0;i<t.size();i++ )
        {
            int c= t[i]-'a';

            if( !v[c].size() )
            {
                f= 0;
                break;
            }

            int pos= upper_bound( v[c].begin(), v[c].end(), now )-v[c].begin();

            if( pos==v[c].size() )
                ans++, now= v[c][0];
            else
                now= v[c][pos];
        }

        if(!f)
            cout<<"-1\n";
        else
            cout<<ans<<"\n";
    }
}
