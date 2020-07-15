#include<bits/stdc++.h>
using namespace std;

int n;
int arr[2007];
int sum[27][2007];

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%d", &n);

        vector<int>v[27];

        for( int i=1;i<=n;i++ )
        {
            scanf("%d", &arr[i]);

            v[ arr[i] ].push_back( i );

            sum[ arr[i] ][i]++;

            for( int j=1;j<=26;j++ )
                sum[j][i]+= sum[j][i-1];
        }

        int ans= 1;

        for( int i=1;i<=26;i++ )
        {
//            cout<<i<<endl;
            for( int j=0;j<v[i].size();j++ )
            {
                for( int k=j;k<v[i].size();k++ )
                {
                    for( int x=1;x<=26;x++ )
                        if( sum[x][v[i][k]-1]-sum[x][v[i][j]]>0 )
                            ans= max( ans, sum[i][ v[i][j] ]+sum[i][n]-sum[i][ v[i][k]-1 ]+sum[x][v[i][k]-1]-sum[x][v[i][j]] );
                }
            }
        }

        printf("%d\n", ans);

        for( int i=0;i<=n;i++ )
            for( int j=0;j<27;j++ )
                sum[j][i]= 0;
    }
}
