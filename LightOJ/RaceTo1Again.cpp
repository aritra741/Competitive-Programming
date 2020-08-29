#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector <int> dv[100007];
double E[100007];

void initialize(void)
{
    for(int i=2;i<=100000;i++)
        for(int j=i;j<=100000;j+=i)
            dv[j].push_back(i);
}

void PreCalc(void)
{
    E[0]=E[1]=0;

    for(int i=2;i<=100000;i++)
    {
        int sz=dv[i].size();

        for(int j=sz-2;j>=0;j--)
            E[i]+= E[ dv[i][j] ];
        E[i]+=sz+1;
        E[i]/=sz;
    }
}

int main()
{
    initialize();
    PreCalc();
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        int n;
        scanf("%d", &n);
        printf("Case %d: %.10f\n", i, E[n]);
    }

}

