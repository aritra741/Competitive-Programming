#include<bits/stdc++.h>
#define M 10007
using namespace std;
const int kinds = 256;///maximum ASCII value of any character of the string
char str[M];
int K, buc[M], r[M], sa[M], X[M], Y[M], high[M];
bool cmp(int *r, int a, int b, int x)
{
    return (r[a] == r[b] && r[a+x] == r[b+x]);
}
vector<int>saa;
int lcp[M];

void suffix_array_DA(int n, int m)
{
    int *x = X, *y = Y, i, j, k = 0, l;
    memset(buc, 0, sizeof(buc));
    for(i = 0; i < n; i++)
        buc[ x[i]=str[i] ]++;
    for(i = 1; i < m; i++)
        buc[i] += buc[i-1];
    for(i = n-1; i >= 0; i--)
        sa[--buc[x[i]]] = i;
    for(l = 1, j = 1; j < n; m = j, l <<= 1)
    {
        j = 0;
        for(i = n-l; i < n; i++)
            y[j++] = i;
        for(i = 0; i < n; i++)
            if(sa[i] >= l)
                y[j++] = sa[i]-l;
        for(i = 0; i < m; i++)
            buc[i] = 0;
        for(i = 0; i < n; i++)
            buc[ x[y[i]] ]++;
        for(i = 1; i < m; i++)
            buc[i] += buc[i-1];
        for(i = n-1; i >= 0; i--)
            sa[ --buc[ x[y[i]] ]] = y[i];
        for(swap(x, y), x[sa[0]] = 0, i = 1, j = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i-1], sa[i], l) ? j-1 : j++;
    }
    for(i = 1; i < n; i++)
        r[sa[i]] = i;
    for(i = 0; i < n-1; high[r[i++]] = k)
        for(k ? k--: 0, j = sa[r[i]-1]; str[i+k] == str[j+k]; k++);
}
void suffix_array_construction(char s[])
{
    int n=strlen(s);
    for(int i=0; i<n; i++)
        str[i]=s[i];
    str[n]='\0';
    suffix_array_DA(n+1,kinds);

    for(int i=1; i<=n; i++)
        saa.push_back(sa[i]);
}
void lcp_construction(char const s[], vector<int> const& p)
{
    int n = strlen(s);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (rank[i] == n - 1)
        {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
}

char s[10007];

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1;t<=tc;t++ )
    {
        scanf("%s", s);

        int n= strlen(s);

        suffix_array_construction(s);
        lcp_construction(s,saa);

        int a,b, ans= 0;
        scanf("%d %d", &a, &b);

        for( int i=a;i<=b;i++ )
            ans+= n-i+1;

        for( int i=0;i<n;i++ )
        {
            int mm= min( b, lcp[i] );
            int nn;

            if(lcp[i]>=a)
                nn= a;
            else
                nn= mm+1;       /// So that the equation has max(0,0) when lcp[i] is smaller than p-q range

            ans-= max(mm-nn+1,0);
        }

        printf("Case %d: %d\n", t, ans);

        saa.clear();
        memset(lcp,0,sizeof(lcp));
    }
}


