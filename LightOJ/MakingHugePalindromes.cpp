#include <bits/stdc++.h>
using namespace std;

int l;
int pre[1000007];
char s[1000007], s1[1000007];

void precal()
{
    int q= -1;

    for( int i=1;i<l;i++ )
    {
        while(q>-1 and s1[q+1]!=s1[i])
            q= pre[q];
        if( s1[q+1]==s1[i] )
            q++;
        pre[i]= q;
    }
}

int kmp()
{
    memset( pre, -1, sizeof(pre) );
    precal();

    int q= -1;
    for( int i=0;i<l;i++ )
    {
        while( q>-1 and s1[q+1]!=s[i] )
            q= pre[q];
        if( s1[q+1]==s[i] )
            q++;
    }

    return 2*l-q-1;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    getchar();
    for( int t=1; t<=tc;t++ )
    {
        scanf("%s", s);
        l= strlen(s);

        for( int i=0;i<l;i++ )
            s1[i]= s[l-i-1];

        printf("Case %d: %d\n", t, kmp());
    }
}
