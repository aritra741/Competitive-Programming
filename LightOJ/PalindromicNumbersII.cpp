#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
       ull n,x=0;
       scanf("%llu", &n);
       ull temp=n;
       while(n>0)
       {
            x=x*10+n%10;
            n/=10;
       }

        if(temp==x)
            printf("Case %d: Yes\n",i);
        else
            printf("Case %d: No\n",i);
    }
}
