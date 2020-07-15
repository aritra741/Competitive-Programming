#include <bits/stdc++.h>
using namespace std;

int arr[100007], sum[100007];

int main()
{
    int n,q;
    scanf("%d %d", &n, &q);

    for( int i=1; i<=n; i++ )
    {
        scanf("%d", &arr[i]);

        sum[i]= sum[i-1];
        if( arr[i]==3 or arr[i]==4 or arr[i]==6 )
            sum[i]++;
    }

    while(q--)
    {
        int l,r;
        scanf("%d %d", &l, &r);

        printf("%d\n", sum[r]-sum[l-1]);
    }
}
