#include <bits/stdc++.h>
#define ll long long
#define mx 5000007
using namespace std;

bool arr[mx];
ll dv[mx], sum[mx];

void sieve()
{
    arr[0]=arr[1]= 1;

    for( ll i=2;i<mx;i++ )
    {
        if( !arr[i] )
        {
            dv[i]++;
            for( ll j=i*2;j<mx;j+=i )
            {
                arr[j]= 1;
                ll tmp= j, cnt= 0;

                while( tmp%i==0 )
                    tmp/= i, cnt++;

                dv[j]+= cnt;
            }
        }
    }

    for( int i=1;i<mx;i++ )
        sum[i]= sum[i-1]+dv[i];
}

int main()
{
    sieve();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int a,b;
        scanf("%d %d", &a, &b);

        printf("%lld\n", sum[a]-sum[b]);
    }
}
