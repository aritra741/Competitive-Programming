#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main()
{
    ull x;

    while(scanf("%llu", &x)==1 and x)
    {
        if( x%9==0 )
            printf("%llu ", ((10*x)/9)-1);

        printf("%llu", (10*x)/9);
        printf("\n");
    }

}
