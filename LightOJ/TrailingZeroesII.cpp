#include <bits/stdc++.h>
#define d(x) cout<<x<<endl;
using namespace std;

int prime_fact2(int x)
{
    int cnt=0;
    while(x>0)
    {
        if(x%2==0)
        {
            cnt++;
            x/=2;
        }
        else
            break;
    }
    return cnt;
}

int prime_fact5(int x)
{
    int cnt=0;
    while(x>0)
    {
        if(x%5==0)
        {
            cnt++;
            x/=5;
        }
        else
            break;
    }
    return cnt;
}

int zero(int x, int n)
{
    int i=n,cnt=0;
    while(x>=n)
    {
        cnt+=x/n;
        n*=i;
    }
    return cnt;
}

int main()
{
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        int n,r,p,q;
        scanf("%d%d%d%d",&n,&r,&p,&q);
        int p2=prime_fact2(p);
        int p5=prime_fact5(p);
        int up2=zero(n,2);
        up2+=p2*q;
        //d(p2)
        int up5=zero(n,5);
        up5+=p5*q;
        //d(up5)
        int down5=zero(r,5)+zero(n-r,5);
        int down2=zero(r,2)+zero(n-r,2);
        int num2=up2-down2;
        int num5=up5-down5;
        //d(down2) d(down5)
        int ZERO=min(num2,num5);
        printf("Case %d: %d\n", i, ZERO);



    }
}
