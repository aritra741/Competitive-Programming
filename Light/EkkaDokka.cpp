#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    ull n;
    for(int i=1;i<=tc;i++)
    {
        scanf("%llu", &n);
        if(n%2!=0)
            printf("Case %d: Impossible\n", i);
        else
        {
            ull temp=2;
            while(1)
            {
                if(n%(temp*2)==0)
                    temp*=2;
                else
                    break;
            }
            printf("Case %d: %llu %llu\n", i, n/temp, temp);
        }
    }

}
