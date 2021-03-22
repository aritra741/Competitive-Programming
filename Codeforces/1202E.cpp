#include<bits/stdc++.h>
#define ll long long
#define M 200007
#define mod 1000000007
using namespace std;
const int kinds = 256;///maximum ASCII value of any character of the string
int nn;
char str[M];
int K, buc[M], r[M], sa[M], X[M], Y[M], high[M];
bool cmp(int *r, int a, int b, int x)
{
    return (r[a] == r[b] && r[a + x] == r[b + x]);
}
vector<int>saa;
int lcp[M];

string t, s;
int n, m;

void suffix_array_DA(int n, int m)
{
    int *x = X, *y = Y, i, j, k = 0, l;
    memset(buc, 0, sizeof(buc));
    for (i = 0; i < n; i++)
        buc[ x[i] = str[i] ]++;
    for (i = 1; i < m; i++)
        buc[i] += buc[i - 1];
    for (i = n - 1; i >= 0; i--)
        sa[--buc[x[i]]] = i;
    for (l = 1, j = 1; j < n; m = j, l <<= 1)
    {
        j = 0;
        for (i = n - l; i < n; i++)
            y[j++] = i;
        for (i = 0; i < n; i++)
            if (sa[i] >= l)
                y[j++] = sa[i] - l;
        for (i = 0; i < m; i++)
            buc[i] = 0;
        for (i = 0; i < n; i++)
            buc[ x[y[i]] ]++;
        for (i = 1; i < m; i++)
            buc[i] += buc[i - 1];
        for (i = n - 1; i >= 0; i--)
            sa[ --buc[ x[y[i]] ]] = y[i];
        for (swap(x, y), x[sa[0]] = 0, i = 1, j = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], l) ? j - 1 : j++;
    }
    for (i = 1; i < n; i++)
        r[sa[i]] = i;
    for (i = 0; i < n - 1; high[r[i++]] = k)
        for (k ? k-- : 0, j = sa[r[i] - 1]; str[i + k] == str[j + k]; k++);
}
void suffix_array_construction(string s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
        str[i] = s[i];
    str[n] = '\0';
    suffix_array_DA(n + 1, kinds);

    for (int i = 1; i <= n; i++)
        saa.push_back(sa[i]);
}
void lcp_construction(string const& s, vector<int> const& p)
{
    int n = s.size();
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
        while (i + k < n && j + k < n && s[i + k] == s[j + k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
}

bool greaterEqual(int sp, int n, const string &ps) {
    int spl = n - sp, sps = ps.size(), o = min(spl, sps);
    for (int i = 0; i < o; i++) {
        if (t[sp + i] > ps[i]) return 1;
        else if (t[sp + i] < ps[i]) return 0;
    }
    return spl >= sps;
}

bool greaterByVal(int sp, int n, const string &ps) {
    int spl = n - sp, sps = ps.size(), o = min(spl, sps);
    for (int i = 0; i < o; i++) {
        if (t[sp + i] > ps[i]) return 1;
        else if (t[sp + i] < ps[i]) return 0;
    }
    return 0;
}

pair<int, int> rangeString(int n, const string &ps) {  // returns [a,b) , not [a,b]
    int lo = 0, hi = n - 1, l = n, r = n;
    while (lo <= hi) {
        auto mid = (lo + hi) >> 1;
        if (greaterEqual(saa[mid], n, ps)) l = mid, hi = mid - 1;
        else lo = mid + 1;
    }
    lo = l, hi = n - 1;
    while (lo <= hi) {
        auto mid = (lo + hi) >> 1;
        if (greaterByVal(saa[mid], n, ps)) r = mid, hi = mid - 1;
        else lo = mid + 1;
    }
    return {l, r};
}

bool match(int mid)
{
    int cnt = 0;

    for ( int j = 0, k = mid; j < m and k < n; j++, k++ )
    {
        if ( t[k] == s[j] )
            cnt++;
        else
            break;
    }

    if (cnt >= m)
        return 1;
    return 0;
}

ll st[M], en[M];
ll shuru[M], shesh[M];
string ss[M];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    n = t.size();
    suffix_array_construction(t);
    lcp_construction(t, saa);
    nn = saa.size();

    int q;
    cin>>q;

    for ( int i = 0; i < q; i++ )
    {
        cin >> ss[i];

        pair<int,int>strRange= rangeString(n,ss[i]);

        st[strRange.first]++;
        st[strRange.second]--;  // [a,b)
    }

    for( int i=1;i<n;i++ )
        st[i]+= st[i-1];
    for( int i=0;i<n;i++ )
        shuru[saa[i]]= st[i];
    
    saa.clear();

    reverse(t.begin(), t.end());
    suffix_array_construction(t);
    lcp_construction(t, saa);

    for ( int i = 0; i < q; i++ )
    {
        reverse( ss[i].begin(), ss[i].end() );

        pair<int,int>strRange= rangeString(n,ss[i]);

        en[strRange.first]++;
        en[strRange.second]--;  // [a,b)
    }
    

    for( int i=1;i<n;i++ )
        en[i]+= en[i-1];
    for( int i=0;i<n;i++ )
        shesh[n-saa[i]-1]= en[i];

    ll ans= 0;

    for( int i=1;i<n;i++ )
        ans+= ( shuru[i]*shesh[i-1] );
    
    cout<< ans ;
}
