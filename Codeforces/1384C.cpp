#include<bits/stdc++.h>
#define inf 1000000000
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;

        vector<int>v(30,inf);
        bool f= 0;
        int ans= 0;

        for( int i=0; i<26; i++ )
        {
            char c= 'a'+i;

            for( int j=0; j<n; j++ )
            {
                if( s[j]==c )
                {
                    if( t[j]<s[j] )
                    {
                        f= 1;
                        break;
                    }
                    if( t[j]==s[j] )
                        continue;

                    v[i]= min( v[i], t[j]-s[j] );
                }
            }

            if(v[i]<inf)
                for( int j=0; j<n; j++ )
                    if( s[j]==c and s[j]<t[j] )
                        s[j]= s[j]+v[i];

            if(v[i]<inf)
                ans++;
        }

        if(f)
            ans= -1;

        cout<< ans <<endl;
    }
}
