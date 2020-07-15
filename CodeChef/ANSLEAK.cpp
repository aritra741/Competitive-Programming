#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        int n,m,k;
        scanf("%d %d %d", &n, &m, &k);

        for( int i=0;i<n;i++ )
        {
            map<int,int>mp;
            int freq= 0, ans;

            for( int j=0;j<k;j++ )
            {
                int p;
                scanf("%d", &p);

                mp[p]++;

                if( mp[p]>freq )
                    freq= mp[p], ans= p;
            }

            printf("%d ", ans);
        }
        printf("\n");
    }
}
