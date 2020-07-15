#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    for( int t=1;t<=tc;t++ )
    {
        int a,b,c;
        cin>>a>>b>>c;

        printf("Case %d: ", t);

        if( c%__gcd(a,b) )
            printf("No\n");
        else
            printf("Yes\n");
    }
}
