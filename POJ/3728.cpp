#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define ll long long
#define M 100007
using namespace std;
const int kinds = 10007;///maximum ASCII value of any character of the string
int str[M];
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
void suffix_array_construction(int s[], int n)
{
    for(int i=0; i<n; i++)
        str[i]=s[i];

    suffix_array_DA(n,kinds);

    for(int i=1; i<=n; i++)
        saa.push_back(sa[i]);


}
void lcp_construction(int s[], int n, vector<int> const& p)
{
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

int s[100007];

int main()
{
    int n,m,k;

    while(scanf("%d %d %d", &n, &m, &k)==3)
    {
        for( int i=0; i<n; i++ )
        {
            int p;
            scanf("%d", &p);

            s[i+m+1]= p;
        }

        s[m]=10006;

        for( int i=0; i<m; i++ )
        {
            int p;
            scanf("%d", &p);

            s[i]= p;
        }

        s[n+m+1]= 0;

//        for( int i=0;i<n+m+1;i++ )
//            cout<<s[i]<<" ";
//        cout<<endl;

        suffix_array_construction(s,n+m+2);
        lcp_construction(s,n+m+2,saa);

        int cnt1= 0, cnt2= 0;

//        for( int i=0;i<=n+m+1;i++ )
//        {
////            cout<<"ashlo "<<saa[i]<<" "<<s[saa[i]]<<" ";
//            for( int j=saa[i];j<=n+m;j++ )
//            {
//                if(s[j]<2)
//                    cout<<"$ ";
//                else
//                    cout<<s[j]<<" ";
//            }
//            cout<<"   "<<lcp[i]<<" "<<endl;
//        }

        for( int i=0; i<n+m; i++ )
        {
            if( lcp[i]>=k and n+m+1-saa[i]<=m and n+m+1-saa[i+1]>m )
                cnt1+= lcp[i]-k+1;
            else if( lcp[i]>=k and n+m+1-saa[i+1]<=m and n+m+1-saa[i]>m )
                cnt1+= lcp[i]-k+1;
        }

        for( int i=0; i<n+m; i++ )
        {
            if( lcp[i]>k and n+m+1-saa[i]<=m and n+m+1-saa[i+1]>m )
                cnt2+= lcp[i]-k;
            else if( lcp[i]>k and n+m+1-saa[i+1]<=m and n+m+1-saa[i]>m )
                cnt2+= lcp[i]-k;
        }

//        cout<<cnt1<<" "<<cnt2<<endl;
        printf("%d\n", cnt1-cnt2);
        saa.clear();
        memset(lcp,0,sizeof(lcp));
    }
}

/*
5 5 2
10000 10000 10000 10000 10000
10000 10000 10000 10000 10000
            */
