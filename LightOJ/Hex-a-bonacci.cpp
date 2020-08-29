#include <bits/stdc++.h>
#define ull unsigned long long
#define MOD 10000007
using namespace std;
int main()
{
    ull a,b,c,d,e,f,n;
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        scanf("%llu %llu %llu %llu %llu %llu %llu",&a,&b,&c,&d,&e,&f,&n);
        ull fn[n+6];
        fn[0]=a;
        fn[1]=b;
        fn[2]=c;
        fn[3]=d;
        fn[4]=e;
        fn[5]=f;
        if(n<=5)
            printf("Case %d: %llu\n", i, fn[n]%MOD);
        else
        {
            for(int j=6;j<=n;j++)
                fn[j]=(fn[j-1]%MOD+fn[j-2]%MOD+fn[j-3]%MOD+fn[j-4]%MOD+fn[j-5]%MOD+fn[j-6]%MOD)%MOD;
            printf("Case %d: %llu\n", i, fn[n]%MOD);
        }

    }


}
