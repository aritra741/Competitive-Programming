#include <bits/stdc++.h>
#define ll long long
using namespace std;

set <ll> st;
set <ll> ::iterator it;

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        ll y,x;
        cin>>y>>x;
        if(y==1)
            st.insert(x);
        else if(y==2)
            st.erase(x);
        else
        {
            it=st.find(x);
            if(it==st.end())
                cout<<"No"<<endl;
            else
                cout<<"Yes"<<endl;
        }
    }
}
