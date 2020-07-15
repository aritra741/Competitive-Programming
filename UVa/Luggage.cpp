#include <bits/stdc++.h>
using namespace std;

int dp[25][210], w[25];
bool vis[25][210];
int n, cap;

int knpsck(int i, int weight)
{
    if(i>n)
        return 0;
    if(vis[i][weight])
        return dp[i][weight];

    int p1,p2;

    if(w[i-1]+weight<=cap)
        p1= w[i-1]+knpsck(i+1, w[i-1]+weight);
    else
        p1=0;
    p2= knpsck(i+1, weight);


    vis[i][weight]=1;

    return dp[i][weight]= max(p1, p2);
}
int main()
{
    int tc;
    scanf("%d", &tc);
    getchar();
    while(tc--)
    {
        string s;
        stringstream ss;

        getline(cin,s);

        ss<<s;

        int cnt=-1,tot=0, p;

        while(ss>>p)
        {
            cnt++;
            w[cnt]=p;
            tot+=p;
        }

        n=cnt+1;

        cap=tot;

        if(tot & 1)
            printf("NO\n");
        else
        {
            cap/=2;

            int ans=knpsck(1,0);

            if(ans==cap)
                printf("YES\n");
            else
                printf("NO\n");
        }

        memset(vis, 0, sizeof(vis));
    }
}
