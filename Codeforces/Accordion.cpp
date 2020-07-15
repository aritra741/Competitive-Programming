#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    int opidx= -, clidx= -1;

    for(int i=0;i<s.size();i++)
    {
        if( s[i]=='[' and opidx==-1)
            opidx= i;
        else if( s[i]==']' and clidx==-1 )
            clidx= i;
    }

    if( opidx==-1 or clidx==-1 )
    {
        cout<<"-1";
        return 0;
    }

    int colf= -1, coll- -1;

    for(int i=0;i<s.size();i++)
    {
        if( s[i]==':' and colf==-1 )
            colf= i;
        else if( s[i]==':' )
            coll= i;
    }

    if(colf==-1 or coll==-1)
    {
        cout<<"-1";
        return 0;
    }

    for(int i=0;i<)
}
