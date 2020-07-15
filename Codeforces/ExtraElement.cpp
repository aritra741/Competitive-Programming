#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

pii arr[200007];
map<int,int> mp;
map<int,int> ::iterator it;

int main()
{
    int n;
    cin>>n;

    for( int i=0; i<n; i++ )
    {
        scanf("%d", &arr[i].f);
        arr[i].s= i+1;
    }

    sort( arr, arr+n );

    for( int i=1; i<n; i++ )
        mp[ arr[i].f-arr[i-1].f ]++;

    int diff, mx= 0;

    for( it=mp.begin(); it!=mp.end(); it++ )
        if( it->second>mx )
            mx= it->second, diff= it->first;

    if( mx!=n-3 and mx!=n-2 and mx!=n-1 )
        return cout<<"-1", 0;

    if(n<=3)
        return cout<<"1", 0;

    if( mx==n-2 )
    {
        if( arr[1].f-arr[0].f==diff )
        {
            bool ff= 1;
            for( int i=2; i<n and ff; i++ )
                if( arr[i].f-arr[i-1].f!=diff )
                    ff= 0;

            if(ff)
                return cout<<arr[0].s, 0;
            else
                return cout<<"-1", 0;
        }

        if( arr[n-1].f-arr[n-2].f==diff )
        {
            bool ff= 1;
            for( int i=1; i<n-1 and ff; i++ )
                if( arr[i].f-arr[i-1].f!=diff )
                    ff= 0;

            if(ff)
                return cout<<arr[n-1].s, 0;
            else
                return cout<<"-1", 0;
        }

        return cout<<"-1", 0;
    }

    if( mx==n-3 )
    {
        int cnt= 0, idx= -1;
        for( int i=1; i<n-1; i++ )
            if( arr[i].f-arr[i-1].f!=diff and arr[i+1].f-arr[i].f!=diff )
                cnt++, idx= i;
        cout<<idx<<endl;
        if( cnt!=1 )
            return cout<<"-1", 0;
        return cout<<arr[idx].s, 0;
    }

    if( mx==n-1 )
        return cout<<"1", 0;

    return cout<<"-1", 0;
}
