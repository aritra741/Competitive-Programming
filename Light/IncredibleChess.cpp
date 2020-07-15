#include <bits/stdc++.h>
using namespace std;

int arr[110];

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1;t<=tc;t++ )
    {
        int n;
        scanf("%d", &n);

        for( int i=0;i<n;i++ )
            scanf("%d", &arr[i]);

        int x= 0, p;

        for( int i=0;i<n;i++ )
            scanf("%d", &p), x^= p-arr[i]-1;

        printf("Case %d: ", t);

        if( !x )
            printf("black wins\n");
        else
            printf("white wins\n");
    }
}
