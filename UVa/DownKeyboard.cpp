#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(getline(cin, s))
    {
        int flag=0;

        deque<char> dq;
        deque<char> ::iterator it=dq.begin();
        int len=s.length();
        for(int i=0; i<len; i++)
        {
            if(s[i]=='[')
                it=dq.begin();
            else if(s[i]==']')
                it=dq.end();
            else
            {
                it=dq.insert(it, s[i]);
                it++;

            }

        }
        for(it=dq.begin(); it!=dq.end(); it++)
            cout<<*it;
        cout<<endl;




    }
}
