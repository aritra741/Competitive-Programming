#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

vector<pii>v;
bool ok[mx];

int main()
{
    int n,md;
    cin>>n>>m>>d;

    for( int i=1; i<=n; i++ )
    {
        int p;
        cin>>p;

        v.push_back( pii(p,i) );
    }

    sort(  v.begin(), v.end() );

    int curr= 0;

    for( int i=1; i<= )
    {
        if( done[i] )
            continue;
        while( curr<n and (v[curr].first-v[i].first<=d or done[ v[curr].first ]) )
            curr++;

        while( curr<n and v[curr] )
    }
}
