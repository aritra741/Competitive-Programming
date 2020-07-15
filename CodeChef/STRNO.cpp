#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        int x,k;
        scanf("%d %d", &x, &k);

        int n= x;
        int ans= 0;

        for( int i=2;i*i<=x;i++ )
        {
            while( x%i==0 )
                x/= i, ans++;
        }

        if(x>1)
            while(n%x==0)
                n/= x, ans++;

        if( ans>=k )
            printf("1\n");
        else
            printf("0\n");
    }
}
