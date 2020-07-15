#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        int n;
        scanf("%d", &n);

        int arr[n+5];
        map<int,int>mp;

        for( int i=0;i<n;i++ )
            scanf("%d", &arr[i]);

        bool f= 1;

        for( int i=0;i<=n;i++ )
        {
            mp[ i+arr[i%n] ]++;

            if(mp[ i+arr[i%n] ]>1)
                f= 0;
        }

        if(!f)
            printf("NO\n");
        else
            printf("YES\n");
    }
}
