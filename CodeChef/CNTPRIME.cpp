#include <bits/stdc++.h>
#define ll long long
#define mx 1e7+7
using namespace std;

int sum[(int)mx];
bool arr[(int)mx];

void sieve()
{
    for( int i=0;i<mx;i++ )
        arr[i]= 1;

    for( ll i=2;i<mx;i++ )
    {
        if( arr[i] )
        {
            for( ll j= i*i;j<mx;j+=i )
                arr[j]= 0;
        }
    }

    for( int i=2;i<mx;i++ )
        sum[i]= sum[i-1]+ (int)arr[i];
}

int main()
{
    sieve();
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        int p,q;
        scanf("%d %d", &p, &q);

        printf("%d\n", sum[q]-sum[p-1]);
    }
}
