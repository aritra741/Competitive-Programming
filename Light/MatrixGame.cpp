#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1;t<=tc;t++ )
    {
        int n, m;
        scanf("%d %d", &n, &m);

        int p, x= 0;

        for( int i=0;i<n;i++ )
        {
            int sum= 0;
            for( int j=0;j<m;j++ )
                scanf("%d", &p), sum+= p;

            x^= sum;
        }

        printf("Case %d: ", t);

        if(x)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
}

