#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        scanf("%d", &n);

        ll arr[n];

        for(int i=0;i<n;i++)
            scanf("%lld", &arr[i]);

        bool flag=0;

        for(int i=0;i<n-1;i++)
            if(arr[i]==arr[i+1])
                flag=1;

        if(!flag)
            printf("non-boring\n");
        else
            printf("boring\n");


    }
}
