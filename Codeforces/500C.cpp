#include<bits/stdc++.h>
#define mx 507
using namespace std;

int w[mx], arr[mx], cnt[mx];
int sum[mx], pos[mx];
int tot;

bool cmp( int a, int b )
{
    return (tot-cnt[a])*w[a]<(tot-cnt[b])*w[b];
}

int main()
{
    int n,m;
    cin>>n>>m;

    for( int i=1;i<=n;i++ )
        cin>>w[i];

    for( int i=1;i<=m;i++ )
        cin>>arr[i], tot+= w[ arr[i] ], cnt[ arr[i] ]++;

    int c[mx];

    for( int i=0;i<n;i++ )
        c[i]= i+1;

    sort( c, c+n, cmp );

    stack<int>st;

    for( int i=n-1;i>=0;i-- )
        st.push(c[i]);

    int ans= 0;

    for( int i=1;i<=m;i++ )
    {
        vector<int>v;
        while(st.top()!=arr[i])
            v.push_back(st.top()), ans+= w[st.top()], st.pop();
        st.pop();
        reverse( v.begin(), v.end() );
        for( auto x: v )
            st.push(x);
        st.push(arr[i]);

        cout<< arr[i] <<" "<<ans<<endl;
    }

    cout<< ans <<endl;
}
