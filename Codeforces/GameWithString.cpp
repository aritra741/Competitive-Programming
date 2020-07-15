#include <bits/stdc++.h>
using namespace std;

stack<char> st;

int main()
{
    string s;
    cin>>s;

    bool first= 1;

    for(int i=0; i<s.size(); i++)
    {
        if( st.empty() )
            st.push(s[i]);
        else
        {
            char c= st.top();
            if( s[i]==c )
            {
                st.pop();
                first= !first;
            }

            else
                st.push( s[i] );
        }
    }

    if(first)
        cout<<"No\n";
    else
        cout<<"Yes\n";
}
