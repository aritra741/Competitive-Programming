#include<bits/stdc++.h>
#define mx 200007
using namespace std;

int arr[mx], p[mx], en[mx];
int mst[mx];

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        int n;
        scanf("%d", &n);

        for( int i=1;i<=n;i++ )
            scanf("%d", &arr[i]);

        int m;
        scanf("%d", &m);

        for( int i=1;i<=m;i++ )
            scanf("%d %d", &p[i], &en[i]), mst[ en[i] ]= max( mst[ en[i] ], p[i] );

        for( int i=n;i>=1;i-- )
            mst[i]= max( mst[i], mst[i+1] );

        int dead= 0;
        int ans= 0;

        while(dead<n)
        {
            ans++;
            int mm= 0;
            int cnt= 0;

            for( int i=dead+1;i<=n;i++ )
            {
                mm= max( mm, arr[i] );

                if( mst[cnt+1]>=mm )
                    cnt++;
                else
                    break;
            }

            if(!cnt)
                break;
            dead+= cnt;
        }

        if(dead!=n)
            printf("-1\n");
        else
            printf("%d\n", ans);

        for( int i=1;i<=n+1;i++ )
            mst[i]= 0;
    }
}
