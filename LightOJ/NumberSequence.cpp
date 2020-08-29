#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main()
{
    int tc;
    ull a, b,n,m;
    scanf("%d", &tc);
    for(int i=1;i<=tc;i++)
    {
        scanf("%llu %llu %llu %llu", &a,&b,&n,&m);
        if(n==0)
            printf("Case %d: %llu\n", i, a);
        else if(n==1)
            printf("Case %d: %llu\n", i, b);
        else if(n==2)
            printf("Case %d: %llu\n", i, a+b);
        else
        {

        }

    }
}
