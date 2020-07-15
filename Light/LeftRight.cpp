#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1;t<=tc;t++ )
    {
        int n;
        scanf("%d", &n);

        int x= 0, p,q;

        for( int i=0;i<n;i++ )
            scanf("%d %d", &p, &q), x^= q-p-1;

        printf("Case %d: ", t);

        if(x)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
}
