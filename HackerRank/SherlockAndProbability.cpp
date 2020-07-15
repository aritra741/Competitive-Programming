#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int len, k;
        scanf("%d %d", &len, &k);

        string s;
        cin>>s;

        ull tot=0;

        for(int i=0;i<len;i++)
        {
            if( s[i]=='1' )
            {
                tot++;

                for(int j=1;j<=k;j++)
                    if( s[i+j]=='1' )
                        tot+=2;
            }
        }

        ull denom= len*len;

        ull g= __gcd( denom, tot );

        printf("%llu/%llu\n", tot/g, denom/g);
    }
}
