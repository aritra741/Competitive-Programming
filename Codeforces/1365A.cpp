#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n,m;
        cin>>n>>m;

        int arr[n+5][m+5];
        set<int>col,row;
        for( int i=0;i<n;i++ )
            for( int j=0;j<m;j++ )
                cin>>arr[i][j];

        for( int i=0;i<n;i++ )
            row.insert(i);
        for( int i=0;i<m;i++ )
            col.insert(i);

        for( int i=0;i<n;i++ )
            for( int j=0;j<m;j++ )
                if( arr[i][j] )
                    {
                        if( row.find(i)!=row.end() )
                            row.erase( i );
                        if( col.find(j)!=col.end() )
                            col.erase( j );
                    }

        if( min( row.size(), col.size() )&1 )
            cout<<"Ashish\n";
        else
            cout<<"Vivek\n";
    }
}
