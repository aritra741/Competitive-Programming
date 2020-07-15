#include <bits/stdc++.h>
using namespace std;

stack <char> st;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        st=stack<char>();
        string s;
        cin>>s;
        int len=s.length();
        if(len & 1)
        {
            cout<<"NO"<<endl;
            continue;
        }

        else
        {
            bool flag= 0;
            for(int i=0; i<len; i++)
            {
                if(s[i]=='[' or s[i]=='{' or s[i]=='(')
                    st.push(s[i]);
                else
                {

                    if(st.empty())
                    {
                        flag=1;
                        continue;
                    }char c=st.top();
                    if( (s[i]==']' and c=='[') or (c=='{' and s[i]=='}') or (s[i]==')' and c=='(') )
                            st.pop();
                }
        }

        if(flag or !st.empty())
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
}
}
