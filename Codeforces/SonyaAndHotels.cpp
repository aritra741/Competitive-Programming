#include <bits/stdc++.h>
using namespace std;
set <long long> st;
set <long long> ::iterator it;
int main()
{
    long long n,d;
    cin>>n>>d;
    long long arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    for(int i=0;i<n;i++)
    {
        st.insert(arr[i]-d);
        st.insert(arr[i]+d);
    }

    int cnt=0;

    for(it=st.begin();it!=st.end();it++)
    {
        bool flag=0;
        for(int i=0;i<n;i++)
            if( abs(arr[i]-*it)<d )
                flag=1;
        if(!flag)
            cnt++;
    }
    cout<<cnt;
}
