#include <bits/stdc++.h>
using namespace std;
bool seg[101];
set<int> st;
set<int>::iterator it;
int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        for(int j=l;j<=r;j++)
            seg[j]=1;
    }

    for(int i=1;i<=m;i++)
        if(!seg[i])
            st.insert(i);
    cout<<st.size()<<endl;
    for(it=st.begin(); it!=st.end();it++)
        cout<< *it <<" ";
}
