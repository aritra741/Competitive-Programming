#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll j=1;
    ll arr[6];

    for(ll i=1;i<=13;i++)
    {
        j*=i;
        if(i>=8)
            arr[i-8]=j;
    }

    int n;

    while(scanf("%d", &n)==1)
    {
        if(n<8 and n>=0)
            printf("Underflow!\n");
        else if(n>13)
            printf("Overflow!\n");
        else if(n>=8 and n<=13)
            printf("%lld\n", arr[n-8]);
        else if(n<0 and (n&1))
            printf("Overflow!\n");
        else
            printf("Underflow!\n");
    }
}
