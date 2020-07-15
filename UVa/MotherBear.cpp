#include <bits/stdc++.h>
using namespace std;

int main()
{
    string t;

    while(getline(cin,t) and t!="DONE")
    {
        string s;
        for(int i=0; i<t.size(); i++)
            if( (t[i]>='a' and t[i]<='z') or (t[i]>='A' and t[i]<='Z'))
                s.push_back(t[i]);
        transform( s.begin(),s.end(),s.begin(), ::tolower );

        bool pal= 1;
        int sz= s.size();

        for(int i=0; i<sz/2; i++)
        {
            if( s[i]!=s[sz-i-1] )
                pal= 0;
            break;
        }

        if(pal)
            cout<<"You won't be eaten!\n";
        else
            cout<<"Uh oh..\n";

    }
}
