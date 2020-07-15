#include<bits/stdc++.h>
using namespace std;

set<int>a,b,porea,poreb;
vector<int>aa,bb,baki;

int main()
{
    int n;
    string s,t;

    cin>>n;
    cin>>s>>t;

    for( int i=0; i<n; i++ )
    {
        if( s[i]!=t[i] )
        {
            if(s[i]=='a')
                aa.push_back(i+1);
            else
                bb.push_back(i+1);
        }
    }

    if( (aa.size()+bb.size())&1 )
        return cout<<"-1\n", 0;

    for( int i=0; i<(int)aa.size()-1; i++ )
        a.insert( aa[i] );

    if( aa.size()&1 )
        baki.push_back( aa[ aa.size()-1 ] );
    else if( aa.size() )
        a.insert( aa[ aa.size()-1 ] );

    for( int i=0; i<(int)bb.size()-1; i++ )
        b.insert( bb[i] );

    if( bb.size()&1 )
        baki.push_back( bb[ bb.size()-1 ] );
    else if( bb.size() )
        b.insert( bb[ bb.size()-1 ] );


    vector< pair<int,int> > v;

    while( !a.empty() )
    {
        int k= 0, l= 0;

        for( auto y: a )
        {
            k= y;
            int x= 0;

            for( auto p: a )
            {
                if(p==y)
                    continue;
                x= p;
                l= p;
                break;
            }

            v.push_back( {y,x} );
            break;
        }

        a.erase( k );
        a.erase( l );
    }

    while( !b.empty() )
    {
        int k= 0, l= 0;

        for( auto y: b )
        {
            k= y;
            int x= 0;

            for( auto p: b )
            {
                if(p==y)
                    continue;
                x= p;
                l= p;
                break;
            }

            v.push_back( {y,x} );
            break;
        }

        b.erase( k );
        b.erase( l );
    }

    if( baki.size()==2 )
        v.push_back( { baki[0], baki[0] } ),
        v.push_back( { baki[0], baki[1] } );

    cout<< v.size() <<"\n";

    for( auto x: v )
        cout<<x.first<<" "<<x.second<<"\n";
}
