#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1;t<=tc;t++ )
    {
        ull x;
        scanf("%llu", &x);
        printf("Case %d: ", t);

        if( x%9==0 )
            printf("%llu ", ((10*x)/9)-1);

        printf("%llu", (10*x)/9);
        printf("\n");
    }

}

