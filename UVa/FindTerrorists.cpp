#include <bits/stdc++.h>
#define MX 10007
using namespace std;

vector <int> dv[MX];
bool arr[MX];

void sieve()
{
    arr[0]=arr[1]=1;

    for(int i=2;i<MX;i++)
    {
        if(!arr[i])
            for(int j=i*i;j<MX;j+=i)
                arr[j]=1;
    }
}

void precalc()
{
    for(int i=1;i<MX;i++)
    {
        for(int j=i;j<MX;j+=i)
            dv[j].push_back(i);
    }
}

int main()
{
    sieve();
    precalc();

    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        int l,r;
        scanf("%d %d", &l, &r);

        bool flag=0;

        for(int i=l;i<=r;i++)
            {
                if(!arr[dv[i].size()])
                    {
                       if(flag)
                            printf(" ");
                       printf("%d", i);
                       flag=1;
                    }
            }

        if(!flag)
            printf("-1");
        printf("\n");
    }

}
