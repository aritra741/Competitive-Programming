#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;
int main()
{
    int tc;
    ull n1,n2,ans;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        scanf("%llu %llu", &n1, &n2);
        if(n2%3==0 || n2%3==2)
        {
            ull temp= (n2-n1)/3;
            temp=(n2-n1)-temp;
            if(n2%3==0 && n1%3!=1)
                temp++;
            else if(n1%3==2 && n2%3==2)
                temp++;
            ans=temp;
        }
        else if(n2%3==1)
        {
            if(n2-n1<3 && n2!=n1)
            {
                ans=n2-n1;
            }
            ull temp=(n2-n1)/3+1;

            temp=(n2-n1)-temp+1;

            ans=temp;
        }
        printf("Case %d: %llu\n", i, ans);
    }
}
