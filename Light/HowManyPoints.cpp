#include <bits/stdc++.h>
using namespace std;

unsigned long long gcd(long long a, long long b)
{
    if(b==0)
        return a;
    gcd(b, a%b);
}

int main()
{
    long long tc,x1,x2,y1,y2;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        unsigned long long ans=0;
        scanf("%lld %lld %lld %lld", &x1,&y1,&x2,&y2);
        if(x1==x2)
            {
                ans=abs(y1-y2)+1;
                printf("Case %d: %llu\n", i, ans);
            }
        else if(y1==y2)
        {
                ans=abs(x1-x2)+1;
                printf("Case %d: %llu\n", i, ans);
        }
        else
        {
            long long mx=max( abs(x1-x2), abs(y1-y2) );
            long long mn= min( abs(x1-x2), abs(y1-y2));
            ans=gcd(mx,mn)+1;
            printf("Case %d: %llu\n", i, ans);
        }
    }
}
