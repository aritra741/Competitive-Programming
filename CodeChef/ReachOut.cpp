#include <bits/stdc++.h>
using namespace std;
set <long long int> st;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        st.clear();
        long long n,temp;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            st.insert(temp);
        }
        cout<<st.size()<<endl;
    }
}
