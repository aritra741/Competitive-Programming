#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;

        set<int> st;

        for(int i=0;i<n;i++)
        {
            int p;
            cin>>p;

            st.insert(p);
        }

        cout<< st.size() <<endl;
    }
}
