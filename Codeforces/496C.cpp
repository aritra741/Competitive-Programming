#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int imp[107];
bool baad[107];
string s[107];

int main()
{
    memset( imp, -1, sizeof(imp) );

    fast
    int n,m;
    cin>>n>>m;

    for( int i=0;i<n;i++ )
        cin>> s[i];

    int cnt= 0;

    for( int i=0;i<n-1;i++ )
    {
        int lst= -1;

        for( int j=0;j<m;j++ )
        {
            if( baad[j] )
                continue;

            if( s[i][j]<s[i+1][j] )
            {
                if( imp[j]==-1 or imp[j]>i )
                    imp[j]= i;

                break;
            }
            if( s[i][j]>s[i+1][j] )
            {
                baad[j]= 1;

                cnt++;

                i= -1;
                break;
//                if( lst>-1 and s[i][lst]==s[i+1][lst] )
//                    imp[lst]= i;
//
//                if( imp[j]>-1 and imp[j]<i )
//                {
//                    i= imp[j]-1;
//                    break;
//                }
            }

            lst= j;
        }
    }

    cout<< cnt <<endl;
}
