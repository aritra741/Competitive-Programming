#include <bits/stdc++.h>
#define d(x) cout<<x<<endl
#define m 100000007LL
#define ll long long
using namespace std;

int arr[60];
int cnt[120];
ll tab[60][1100];
bool vis[60][1100];
int n,cap;

ll rec( int i, int curr )
{
    if(curr==0)
        return 1;
    if(i>n)
        return 0;
    if(vis[i][curr])
        return tab[i][curr];

    ll tot=0;

    for(int j=1;j<=cnt[i-1];j++)
    {
        if(curr-j*arr[i-1]>=0)
            tot= (tot%m+ rec( i+1, curr-j*arr[i-1] )%m)%m;
        else
            break;
    }

    tot= (tot%m+rec(i+1, curr)%m)%m;

    vis[i][curr]=1;

    return tab[i][curr]=tot%m;

}

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int t=1;t<=tc;t++)
    {
        scanf("%d %d", &n, &cap);

        for(int i=0;i<n;i++)
            scanf("%d", &arr[i]);

        for(int i=0;i<n;i++)
            scanf("%d", &cnt[i]);

        printf("Case %d: %lld\n", t, rec(1, cap));

        memset(vis, 0, sizeof(vis));
    }
}
