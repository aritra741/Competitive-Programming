#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

multiset<int, greater<int> > st;
multiset<int, greater<int> > ::iterator it;
vector<int> v;
int arr[250007];

int main()
{
    int n;
    scanf("%d", &n);

    int mx= -1, smx= -1;

    for( int i=0; i<n*n; i++ )
    {
        int p;
        scanf("%d", &p);

        st.insert( p );

        if( p>mx )
            smx= mx, mx= p;
        else if( p>smx and p<=mx )
            smx= p;
    }


    if( n==1 )
        return cout<<*(st.begin())<<endl, 0;

    int cnt= 0;

    v.push_back(mx);
    v.push_back(smx);
    st.erase( st.find(mx) );
    st.erase( st.find(smx) );
    st.erase( st.find( __gcd( mx, smx ) ) );
    st.erase( st.find( __gcd( mx, smx ) ) );

    while( !st.empty() )
    {
        bool f= 0;

        int pp;
        for( auto x: st )
        {
            pp= x;
            st.erase( st.find( pp ) );
            break;
        }

        for( int i=0; i<v.size(); i++ )
            st.erase( st.find( __gcd( v[i], pp ) ) ),
            st.erase( st.find( __gcd( v[i], pp ) ) );
        v.push_back(pp);
    }

    for( int i=0; i<v.size(); i++ )
        printf("%d ", v[i]);
}
