#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n,m;
        cin>>n>>m;

        string s[n];

        for( int i=0;i<n;i++ )
            cin>>s[i];

        if(n==1)
        {
            cout<<s[0]<<"\n";
            continue;
        }

        int idx= -1;
        char val= 25;
        bool f= 0;

        for( int x=0;x<m;x++ )
        {
            if(f)
                break;
            for( char c='a';c<='z';c++ )
            {
                int mx= 0;
                for( int i=1;i<n;i++ )
                {
                    int cnt= 0;

                    for( int j=0;j<m;j++ )
                    {
                        if( j==x and s[i][j]!=c )
                            cnt++;
                        if( j!=x and s[i][j]!=s[0][j] )
                            cnt++;
                    }

                    mx= max( mx, cnt );
                }

                if(mx<=1)
                {
                    f= 1;
                    idx= x;
                    val= c;
                    break;
                }
            }
        }

        if(f)
        {
            s[0][idx]= val;
            cout<<s[0]<<"\n";
        }
        else
            cout<<"-1\n";
    }
}
