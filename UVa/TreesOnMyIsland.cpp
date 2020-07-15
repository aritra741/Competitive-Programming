
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    while(1)
    {
        int n;
        scanf("%d", &n);

        if(!n)
            break;

        ll x[n+1],y[n+1];

        for(int i=0;i<n;i++)
            scanf("%lld %lld", &x[i], &y[i]);

        x[n]= x[0];
        y[n]= y[0];

        double area= 0;

        for(int i=0;i<n;i++)
            area+=( x[i]*y[i+1] - x[i+1]*y[i] );

        area= abs(area);

        ll lattice=0;

        for(int i=0;i<n;i++)
            lattice+= __gcd( llabs(y[i+1]-y[i]), llabs(x[i+1]-x[i]) );

        printf("%.0f\n", (area-lattice+2)/2.0);

    }
}
