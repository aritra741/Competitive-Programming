#include <bits/stdc++.h>
#define mx 1000007
using namespace std;

int l;
int pre[2*mx];
char s[2*mx];

void precal()
{
    int q= -1;

    for( int i=1; i<l+l+1; i++ )
    {
        while(q>-1 and s[q+1]!=s[i])
            q= pre[q];
        if( s[q+1]==s[i] )
            q++;
        pre[i]= q;
    }
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        memset(pre,-1,sizeof(pre));
        scanf("%s", s);
        l= strlen(s);
        s[l]= '#';
        for( int i=l-1, j=l+1 ;i>=0;i--,j++ )
            s[j]= s[i];

        precal();

        int ans= 0;

        for( int i=l;i<l+l+1;i++ )
            ans= max(pre[i]+1, ans);

        for( int i=ans-1;i>=0;i-- )
            printf("%c", s[i]);
        printf("\n");
    }
}
