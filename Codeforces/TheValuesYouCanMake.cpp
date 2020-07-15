#include <bits/stdc++.h>
using namespace std;

int ans[510], arr[510];
bool vis[510][510][510];
int n,k,cnt;
set<int> st;

void rec( int i, int tot, int sub )
{
    if(tot>k)
        return;

    if( i>n )
    {
        if( tot==k )
        {
            ans[sub]= 1;
            st.insert(sub);
            return;
        }
        return;
    }

    if( vis[i][tot][sub] )
        return;

    rec( i+1, tot+arr[i], sub+arr[i] );     /// Take in both
    rec( i+1, tot+arr[i], sub );            /// Not in the subset
    rec( i+1, tot, sub );                   /// Not taking it

    vis[i][tot][sub]= 1;
}

int main()
{
    cin>>n>>k;

    for( int i=1; i<=n; i++ )
        cin>>arr[i];

    rec( 1,0,0 );

    cout<< st.size() <<endl;
    for( int i=0; i<=k; i++ )
        if( ans[i] )
            cout<< i <<" ";
}
