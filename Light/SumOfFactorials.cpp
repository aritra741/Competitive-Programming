#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull f[21];

void fact(void)
{
    f[0]=1;
    for(int i=1;i<=20;i++)
       {
           ull ans=1;
           for(int j=1;j<=i;j++)
    {
        ans*=j;
    }
    f[i]=ans;
       }
}

int main()
{
    fact();
    int cnt=0;
    int tc;
    scanf("%d", &tc);
    for(int i=1;i<=tc;i++)
    {
        ull p;
        scanf("%llu", &p);
        bool arr[21]={0};
        int flag=-1;
        for(int q=20;q>=0;q--)
        {

            if(f[q]<=p)
                {

                    p-=f[q];
                    arr[q]=1;
                    if(flag==-1)
                        flag=q;
                }

        }
        if(p==0)
        {
            printf("Case %d: ",i);
            for(int cl=0;cl<21;cl++)
            {
                if(arr[cl]==1)
                    {printf("%d!",cl);
                if(cl!=flag)
                    printf("+");}
            }
            printf("\n");
        }
        else
            printf("Case %d: impossible\n",i);

    }
}
