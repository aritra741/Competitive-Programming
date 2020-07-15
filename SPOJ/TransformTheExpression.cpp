#include <bits/stdc++.h>
using namespace std;

stack<char> st;
string ans;

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        string s;
        cin>>s;

        for(int i=0; i<s.size(); i++)
        {
            if( s[i]>='a' and s[i]<='z' )
                ans+=s[i];
            else if(s[i]=='(')
                st.push(s[i]);
            else if( s[i]==')' )
            {
                while( !st.empty() and st.top()!='(' )
                {
                    ans+=st.top();
                    st.pop();
                }
                if(st.top()=='(')
                    st.pop();
            }

            else if( s[i]=='-' )
            {
                while( !st.empty() and ( st.top()=='-' or st.top()=='+' or st.top()=='*' or st.top()=='/' or st.top()=='^' ) )
                {
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            else if( s[i]=='+' )
            {
                while( !st.empty() and ( st.top()=='+' or st.top()=='-' or st.top()=='*' or st.top()=='/' or st.top()=='^' ) )
                {
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            else if( s[i]=='*' )
            {
                while( !st.empty() and ( st.top()=='*' or st.top()=='/' or st.top()=='^' ) )
                {
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            else if( s[i]=='/' )
            {
                while( !st.empty() and ( st.top()=='*' or st.top()=='/' or st.top()=='^' ) )
                {
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            else if( s[i]=='^' )
            {
                while( !st.empty() and ( st.top()=='^' or st.top()=='/' or st.top()=='^' ) )
                {
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty())
        {
            char tp= st.top();
            st.pop();
            if(tp=='(' or tp==')')
                continue;
            ans+=tp;
        }
        cout<<ans<<endl;

        ans.clear();
        st= stack<char>();
    }
}

