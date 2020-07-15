#include <bits/stdc++.h>
#define pii pair<int,char>
#define f first
#define s second
using namespace std;

vector<pii> groups;

int ret()
{
    int mn= groups[0].f;

    for( int i=1;i+1<groups.size();i++ )
        mn= min( mn, (groups[i].f+1)/2 );       /// Because points get destroyed simultaneously

    mn= min(mn, groups[(int)groups.size()-1].f );

    groups[0].f-= mn;
    groups[(int)groups.size()-1].f-= mn;

    for( int i=1;i+1<groups.size();i++ )
        groups[i].f-= 2*mn;

    auto it = remove_if(groups.begin(), groups.end(), [](const pii& p) { return p.f <= 0; });
    groups.erase(it, groups.end());

    for( size_t i=0;i+1<groups.size();i++ )
    {
        if( groups[i+1].s==groups[i].s )
            groups[i+1].f+= groups[i].f, groups[i].f= 0;
    }

    it = remove_if(groups.begin(), groups.end(), [](const pii& p) { return p.f <= 0; });
    groups.erase(it, groups.end());

    return mn;
}

int  main()
{
    string S;
    cin>>S;

    int len=0, c= S[0];
    for( int i=0;i<S.size();i++ )
    {
        if( S[i]!=c and i )
            groups.push_back( pii(len,c) ), len= 1, c= S[i];
        else
            len++;
    }

    groups.push_back( pii(len,c) );

    int ans= 0;
    while( groups.size()>1 )
        ans+= ret();

    cout<< ans <<endl;
}
