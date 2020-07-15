#include <bits/stdc++.h>
using namespace std;

int l;
int pre[100007];
char s[100007], s1[100007];

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

    return q+1;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while( scanf("%s", s)!=EOF )
    {
        l= strlen(s);

        for( int i=0;i<l;i++ )
            s1[i]= s[l-i-1];

        int extra= kmp();

        printf("%s", s);

        for( int i=extra;i<l;i++ )
            printf("%c", s1[i]);
        printf("\n");
    }
}
