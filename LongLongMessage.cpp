#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define M 200007
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
        for(k ? k--: 0, j = sa[r[i]-1]; str[i+k] == str[j+k]; k++)cout<<i+k<<" "<<j+k<<" "<<str[i+k]<<" "<<str[j+k]<<endl;;
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

char s[200007], tt[200007];

int main()
{
    scanf("%s", s);
    scanf("%s", tt);

    int n= strlen(s);
    int m= strlen(tt);
    int p= n;
    int q= m;

    s[n]= '$';

    for( int i=0; i<m; i++ )
        s[i+n+1]= tt[i];
    s[n+m+1]= 0;

    n= n+m+1;

    suffix_array_construction(s);
    lcp_construction(s,saa);

    int len= 0;

    for( int i=0; i<n-1; i++ )
    {
        if( lcp[i]>len and n-saa[i]<=q and n-saa[i+1]>q )
            len= lcp[i];
        else if( lcp[i]>len and n-saa[i]>q and n-saa[i+1]<=q )
            len=lcp[i];
    }

    printf("%d\n", len);
}

