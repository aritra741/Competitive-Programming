#include<bits/stdc++.h>
#define mx 1007
#define pii pair<int,int>
using namespace std;

int par[mx], Size[mx];
int arr[mx], idx[mx];
int pp[mx];

bool cmp( int u, int v )
{
    return v[u].size()<
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        int n;
        scanf("%d", &n);

        vector<int>v[mx];

        for( int i=0; i<=1000; i++ )
            par[i]= i, Size[i]= 1, idx[i]= -1;

        for( int i=0; i<n; i++ )
        {
            scanf("%d", &arr[i]);

            for( int j=2; j*j<=arr[i]; j++ )
            {
                if( arr[i]%j==0 )
                {
                    v[j].push_back(i);

                    while(arr[i]%j==0)
                        arr[i]/= j;
                }
            }

            if( arr[i]>1 )
                v[ arr[i] ].push_back(i);
        }

        for( int i=0;i<mx;i++ )
            pp[i]= i;

        sort( pp, pp+n,  )

        printf("%d\n", k );

        for( int i=0;i<n;i++ )
            printf("%d ", idx[ Find(i) ]+1 );

        printf("\n");
    }
}
