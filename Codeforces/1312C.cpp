#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[35];

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        ll n,k;
        cin>>n>>k;

        for( int i=0; i<n; i++ )
            cin>> arr[i];

        set<ll>st;
        bool f= 1;

        for( int i=0; i<n; i++ )
        {
            ll p= arr[i];
            int cnt= 1;
            ll x;

            while(p>0)
            {
                x= 1, cnt= 0;

                while(x*k<=p)
                    x*= k, cnt++;

                if( st.find(cnt)!=st.end() )
                {
                    f= 0;
                    break;
                }
                st.insert(cnt);
                p-= x;
            }
        }

        if(f)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
