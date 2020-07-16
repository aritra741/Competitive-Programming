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

        int arr[n+5];
        set<int>st;
        bool f= 0;

        for( int i=0;i<n;i++ )
        {
            cin>>arr[i], st.insert(arr[i]);

            if(i and arr[i]==arr[i-1])
                f= 1;
        }

        if(st.size()==1)
        {
            cout<<"1\n";

            for( int i=0;i<n;i++ )
                cout<<"1 ";
            cout<<"\n";
        }

        else if( st.size()==2 )
        {

        }
    }
}
