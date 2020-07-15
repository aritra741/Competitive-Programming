#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    while(1)
    {
        int n;
        scanf("%d",&n);

        if(!n)
            break;

        ll arr[n];
        ll ending=0, mx=-10000000000;
        bool found=0;

        for(int i=0;i<n;i++)
        {
            scanf("%lld", &arr[i]);

            if( arr[i]>=0 )
                found=1;

            ending+=arr[i];

            mx = max( mx, ending );

            if(ending<0)
                ending=0;
        }

        if(!found or mx==0)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %lld.\n", mx);

    }
}
