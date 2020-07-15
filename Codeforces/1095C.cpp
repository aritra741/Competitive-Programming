#include<bits/stdc++.h>
using namespace std;

multiset<int, greater<int> >st;

int main()
{
    int n,k;
    cin>>n>>k;

    int mn= __builtin_popcount(n);

    if(mn>k)
        return cout<<"NO\n", 0;

    int mx= 0;
    for( int i=0;i<=30;i++ )
        if( n&(1<<i) )
            st.insert( 1<<i ), mx+= (1<<(i+1))-1;

    if( mx<k )
        return cout<<"NO\n", 0;

    while( st.size()<k )
    {
        int val= 0;
        for( auto x: st )
        {
            if( x>1 )
            {
                val= x;
                break;
            }
        }

        if(val)
            st.erase( st.find(val) ),
            st.insert(val/2),
            st.insert(val/2);
        else
            break;
    }

    if( st.size()!=k )
        return cout<<"NO\n", 0;

    cout<<"YES\n";

    for( auto x: st )
        cout<<x<<" ";
}
