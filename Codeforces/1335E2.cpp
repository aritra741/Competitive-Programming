#include<bits/stdc++.h>
using namespace std;

int sum[207][200007];

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        int n;
        scanf("%d", &n);

        vector<int>pos[207];
        int ans= 0;

        for( int i=1;i<=n;i++ )
        {
            int p;
            scanf("%d", &p);

            sum[p][i]++;

            for( int j=1;j<=200;j++ )
                sum[j][i]+= sum[j][i-1], ans= max( ans, sum[j][i] );

            pos[p].push_back(i);
        }

        for( int i=1;i<=200;i++ )
        {
            for( int j=0;j<pos[i].size();j++ )
            {
                int k= (int)pos[i].size()-j-1;

                if( k<=j )
                    break;

                int l= pos[i][j];
                int r= pos[i][k];

                for( int p=1;p<=200;p++ )
                    ans= max( ans, (j+1)*2+sum[p][r-1]-sum[p][l] );
            }
        }

        printf("%d\n", ans);

        for( int i=1;i<=200;i++ )
            for( int j=0;j<=n+1;j++ )
                sum[i][j]= 0;
    }
}
