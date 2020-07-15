#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1; t<=tc; t++ )
    {
        int n;
        scanf("%d", &n);

        int x= 0, p, one= 0;

        for( int i=0; i<n; i++ )
            scanf("%d", &p), x^= p, one= (p==1)?one+1:one;

        printf("Case %d: ", t);

        if( n-one )
        {
            if( !x )
                printf("Bob\n");
            else
                printf("Alice\n");
        }
        else
        {
            if( one&1 )
                printf("Bob\n");
            else
                printf("Alice\n");
        }
    }
}
