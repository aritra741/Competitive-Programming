#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        set<int> st;
        st.insert(0);
        st.insert(1);

        int n;
        cin>>n;

        for( int i=1;i*i<=n;i++ )
            st.insert( n/(n/i) ),
            st.insert( (n/i) );

        cout<<st.size()<<endl;

        for( auto x: st )
            cout<<x<<" ";
        cout<<endl;
    }
}
