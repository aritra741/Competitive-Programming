#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;

        int arr[n];

        for(int i=0;i<n;i++)
            cin>>arr[i];

        set<bool>st;

        for( int i=0;i<n;i++ )
        {
            bool p;
            cin>>p;

            st.insert(p);
        }

        if( is_sorted( arr, arr+n ) or st.size()>1 )
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}
