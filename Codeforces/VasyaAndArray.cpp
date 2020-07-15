#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

vector<pii> sorted, nots;
int arr[1010], issort[1010][1010];

int main()
{
    int n,m;
    cin>>n>>m;

    for( int i=0; i<n; i++ )
        arr[i]= 1;

    while(m--)
    {
        int t,p,q;
        cin>>t>>p>>q;

        if(t)
            sorted.push_back( pii(p-1,q-1) );
        else
            nots.push_back( pii( p-1, q-1 ) );
    }

    for( int i=0; i<sorted.size(); i++ )
        for( int j=sorted[i].first; j<sorted[i].second; j++ )
            issort[j][j+1]= 1;

    sort( nots.begin(),nots.end(), greater<pii>() );

    for( int i=0; i<nots.size(); i++ )
    {
        bool f= 0;
        for( int j=nots[i].first; j<nots[i].second; j++ )
            if( !issort[j][j+1] )
            {
                arr[j]= arr[j+1]+1, f= 1;
                break;
            }

        if( !f )
            return cout<<"NO",0;
    }

    cout<<"YES\n";
    for( int i=0; i<n; i++ )
        cout<< arr[i] <<" ";

}
