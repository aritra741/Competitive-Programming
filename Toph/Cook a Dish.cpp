#include<bits/stdc++.h>
using namespace std;

int f[11];

int main()
{
    f[0]= 1;
    for( int i=1;i<=10;i++ )
        f[i]= i*f[i-1];

    int tc;
    cin>>tc;

    while(tc--)
    {
        int k;
        string s;
        cin>>s;
        cin>>k;

        bool ff= 0;

        for( int i=0;i<s.size();i++ )
            if(s[i]=='0')
                ff= 1;

        int ans= f[s.size()]/f[ s.size()-k ];

        if(ff)
            ans-= f[s.size()-1]/f[s.size()-k];

        cout<<ans<<endl;
    }
}
