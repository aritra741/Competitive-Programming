#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        string s;
        int n;cin>>n>>s;
        if(s=="Alice")
        {
            if(n%3==1)
                cout<<"Case "<<i<<": Bob"<<endl;
            else
                cout<<"Case "<<i<<": Alice"<<endl;
        }
        else
        {
            if(n%3==0)
                cout<<"Case "<<i<<": Alice"<<endl;
            else
                cout<<"Case "<<i<<": Bob"<<endl;
        }

    }
}
