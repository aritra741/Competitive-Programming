#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;
    getchar();
    while(tc--)
    {
        string s;
        stack<char> st;
        bool flag= 1;
        getline(cin,s);

        for(int i=0; i<s.size(); i++)
        {
            if( s[i]=='(' or s[i]=='[' )
                st.push( s[i] );
            else if( s[i]==')' )
            {
                if( st.empty() or st.top()!='(')
                {
                    flag= 0;
                    break;
                }
                else
                    st.pop();
            }
            else
            {
                if( st.empty() or st.top()!='[' )
                {
                    flag= 0;
                    break;
                }
                else
                    st.pop();
            }
        }

        if(st.size())
            flag= 0;

        if(flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}
