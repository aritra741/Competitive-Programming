#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        string s;
        cin>>s;

        set<char> st;
        sort(s.begin(), s.end());

        for(int i=0;i<s.size();i++)
        {
            st.insert(s[i]);
        }

        if(st.size()==1)
            cout<<"-1\n";
        else
            cout<<s<<endl;
    }
}
