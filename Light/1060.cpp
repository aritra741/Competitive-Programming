#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll f[21];

void init()
{
    f[0]= 1;

    for( int i=1;i<=20;i++ )
        f[i]= f[i-1]*i;
}

int cnt[27];

int main()
{
    init();
    int tc;
    scanf("%d", &tc);

    for( int t=1;t<=tc;t++ )
    {
        memset(cnt,0,sizeof(cnt));
        char s[25], ans[25];
        ll n;

        scanf("%s %lld", s, &n);

        int len= strlen(s);

        for( int i=0;i<len;i++ )
            cnt[s[i]-'a']++;

        ll totways= f[len];

        for( int i=0;i<26;i++ )
            totways/= f[cnt[i]];

        if(totways<n)
        {
            printf("Case %d: Impossible\n", t);
            continue;
        }

        for( int i=0;i<len;i++ )
        {
            for( int j=0;j<26;j++ )
            {
                if( !cnt[j] )
                    continue;

                cnt[j]--;

                ll ways= f[len-i-1];

                for( int k=0;k<26;k++ )
                    ways/= f[cnt[k]];

                if(ways<n)
                    cnt[j]++, n-= ways;
                else
                {
                    ans[i]= j+'a';
                    break;
                }
            }
        }

        ans[len]= 0;

        printf("Case %d: %s\n", t, ans);
    }
}
