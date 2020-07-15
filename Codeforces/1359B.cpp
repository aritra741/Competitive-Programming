#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n,m,x,y;
        cin>>n>>m>>x>>y;

        ll ans= 0;

        for( int i=0;i<n;i++ )
        {
            string s;
            cin>>s;

            int tot= 0, nitepari= 0;
            int cnt= 0;

            for( int j=0;j<s.size();j++ )
            {
                if( s[j]=='.' )
                    tot++, cnt++;
                else if(cnt)
                    nitepari+= cnt/2, cnt= 0;
            }

            if(cnt)
                nitepari+= cnt/2, cnt= 0;

            ans+= min( nitepari*y+(tot-nitepari*2)*x, tot*x );
        }

        cout<< ans <<endl;
    }
}

