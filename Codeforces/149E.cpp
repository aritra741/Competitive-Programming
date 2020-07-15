#include <bits/stdc++.h>
using namespace std;

string s, ss;
int lps[200007], pre[200007], suff[200007];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string t,q;
    cin>>t;

    q= t;
    reverse( q.begin(), q.end() );

    int qq;
    cin>>qq;

    int ans= 0;

    int pp= 0;

    while(qq--)
    {
        cin>>s;

        ss.clear();
        ss= s;
        ss+= '#';
        ss+= t;

        lps[0] = 0;
        int till= 0;

        for (int i = 1; i < ss.size(); i++)
        {
            int j = lps[i - 1];
            while (j > 0 && ss[i] != ss[j])
                j = lps[j - 1];
            if (ss[i] == ss[j])
                j++;
            lps[i] = j;

            pre[i]= max( lps[i], till );
            if( i>s.size() )
                till= max( pre[i], till );
        }

        ss.clear();
        reverse( s.begin(), s.end() );

        ss+= s;
        ss+= '#';
        ss+= q;

        lps[0] = 0;
        till= 0;

        for (int i = 1; i < ss.size(); i++)
        {
            int j = lps[i - 1];
            while (j > 0 && ss[i] != ss[j])
                j = lps[j - 1];
            if (ss[i] == ss[j])
                j++;
            lps[i] = j;

            suff[i]= max( lps[i], till );
            if( i>s.size() )
                till= max( suff[i], till );
        }

        int len= 0;

        for( int i=s.size()+1;i<ss.size();i++ )
            if( (int)ss.size()-i-2>=0 )
                len= max( len, pre[i]+suff[s.size()+1+ss.size()-i-2] );

        len= max( len, pre[ ss.size()-1 ] );
        len= max( len, suff[ ss.size()-1 ] );

        if( len>=s.size() and s.size()>1 )
            ans++;
    }

    cout<< ans <<'\n';
}

