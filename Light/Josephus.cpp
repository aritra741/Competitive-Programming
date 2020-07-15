#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull jo(ull n, ull k)
{

    if(n==1)
        return 1;
    return (jo(n-1,k)+k-1)%n+1;
}

int main()
{
    int tc;
    cin>>tc;
    ull n,k;
    for(int i=1;i<=tc;i++)
    {
        scanf("%llu %llu", &n,&k);
        ull ans=jo(n,k);
        printf("Case %d: %llu\n", i, ans);
    }

}
