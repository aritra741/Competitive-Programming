#include <bits/stdc++.h>
#define ull unsigned long long
#define m 1000000007
using namespace std;

set <char> st;
string arr[107];

int main()
{
    int n,len;
    cin>>n>>len;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    ull ans=1;

    for(int i=0;i<len;i++)
    {
        st.clear();
        for(int j=0;j<n;j++)
            st.insert( arr[j][i] );
        ans= ( (ans%m)*(st.size()%m) ) %m;
    }

    cout<<ans<<endl;

}
