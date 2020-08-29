#include <bits/stdc++.h>
#define ll long long
#define m 100000007LL
using namespace std;

int tab[10001];
int arr[100];

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int t=1; t<=tc; t++)
    {
        int n,k;
        scanf("%d %d", &n, &k);

        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);

        memset(tab, 0, sizeof(tab));

        tab[0]=1;

        for(int i=0;i<n;i++)
            for(int j=arr[i];j<=k;j++)
                tab[j]= ((tab[j]%m)+tab[j-arr[i]]%m)%m;

        printf("Case %d: %lld\n", t, tab[k]%m);
    }
}
