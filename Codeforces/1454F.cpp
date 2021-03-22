#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
#define mod 1000000007
#define mx 200007
#define pii pair<int,int>
#define pci pair<int,int>
#define ff first
#define ss second
#define piii pair<int,pii>
using namespace std;

int t1[mx][21], lg2[mx], t2[mx][21];
int arr[mx];

void f( int n )
{
    int i, j, k, m, l, r, q;
    lg2[1] = 0;
    for (i = 2; i <= n; i++) lg2[i] = lg2[i / 2] + 1;
    for (i = 1; i <= n; i++) t1[i][0] = arr[i], t2[i][0] = arr[i];
    for (j = 1; j <= 20; j++) for (i = 1; i + (1 << (j - 1)) <= n; i++) t1[i][j] = min(t1[i][j - 1], t1[i + (1 << (j - 1))][j - 1]);
    for (j = 1; j <= 20; j++) for (i = 1; i + (1 << (j - 1)) <= n; i++) t2[i][j] = max(t2[i][j - 1], t2[i + (1 << (j - 1))][j - 1]);        
}

int squery1( int l, int r )
{
    // int ans = min(ans, t[l][i]), l += (1 << i);
    int k = lg2[r - l + 1];
    int ans = min(t1[l][k], t1[r - (1 << k) + 1][k]);

    return ans;
}

int squery2( int l, int r )
{
    // int ans = min(ans, t[l][i]), l += (1 << i);
    int k = lg2[r - l + 1];
    int ans = max(t2[l][k], t2[r - (1 << k) + 1][k]);

    return ans;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        for ( int i = 1; i <= n; i++ )
            cin >> arr[i];

        f(n);

        int pre[n + 5], suff[n + 5];
        pre[1] = arr[1];
        suff[n] = arr[n];

        for ( int i = 2; i <= n; i++ )
            pre[i] = max( pre[i - 1], arr[i] );
        for ( int i = n - 1; i >= 1; i-- )
            suff[i] = max( suff[i + 1], arr[i] );

        bool f= 0;
        int out, lf, rt;

        for ( int i = 2; i < n; i++ )
        {
            int x = arr[i];

            int baam = i, daan = i;

            int l = 1, r = i;

            if ( i > 1 )
            {
                int ans = i;
                while (l <= r)
                {
                    int q = squery1( mid, i );

                    if (q != x)
                        l = mid + 1;
                    else
                        ans = mid, r = mid - 1;
                }

                baam = ans;
            }

            l = i, r = n;

            if ( i < n )
            {
                int ans = i;
                while (l <= r)
                {
                    int q = squery1( i, mid );

                    // cout<<x<<" "<<l<<" "<<r<<" "<<q<<endl;

                    if (q != x)
                        r = mid - 1;
                    else
                        ans = mid, l = mid + 1;
                }

                daan = ans;
            }

            baam= max( baam, 2 );
            daan= min( daan, n-1 );

            if( baam<i and arr[baam]==arr[i] )
                baam++;
            if( daan>i and arr[daan]==arr[i] )
                daan--;

            if( pre[baam-1]==suff[daan+1] and pre[baam-1]==arr[i] )
            {
                f= 1;
                out= daan-baam+1;
                lf= baam-1;
                rt= n-daan;
                break;
            }

            // cout<<i<<" "<<baam<<" "<<daan<<" "<<pre[baam-1]<<" " <<suff[daan+1]<<endl;
        }

        if(f)
            cout<<"YES\n"<<lf<<" "<<out<<" "<<rt<<"\n";
        else
            cout<<"NO\n";

    }
}