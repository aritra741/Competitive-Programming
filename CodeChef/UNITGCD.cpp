#include<bits/stdc++.h>
#define sf(x) scanf("%d", &x)
#define pf(x) printf("%d", x)
#define __ printf("\n");
#define space printf(" ");
using namespace std;

int main()
{
    int tc;
    sf(tc);

    while(tc--)
    {
        int n;
        sf(n);

        if(n==1)
        {
            pf(1);
            __;
            pf(1);
            space;
            pf(1);
            __;
            continue;
        }

        int i=1;

        pf(n/2);

        __;
        pf( min(n,3) );
        space;

        for( ;i<=min( n,3 );i++ )
        {
            pf(i);
            space;
        }
        __;

        int baki= n/2;
        baki--;

        while(baki--)
        {
            pf( min( n-i+1, 2 ) );
            space;
            pf(i);
            space;
            if(i+1<=n)
                pf(i+1);
            __;
            i+=2;
        }
    }
}
