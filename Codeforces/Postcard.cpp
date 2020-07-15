#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    string s;
    cin>>s>>k;

    int rem= 0, add= 0, sz= 0;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='?')
            rem++;
        else if(s[i]=='*')
            rem++, add++;
        else
            sz++;
    }

    if( k<sz )
    {
        if( rem<sz-k )
            {
                cout<<"Impossible\n";
                return 0;
            }

        rem= sz-k;
        for(int i=0;i<s.size();i++)
        {
            if( rem and i!=s.size()-1 and s[i]!='?' and s[i]!='*' and (s[i+1]=='?' or s[i+1]=='*') )
                rem--;
            else if( s[i]!='?' and s[i]!='*' )
                cout<< s[i];
        }
    }

    else if( k>sz )
    {
        if( !add )
        {
            cout<<"Impossible\n";
            return 0;
        }

        add= k-sz+1;

        for(int i=0;i<s.size();i++)
        {
            if( i!=s.size()-1 and add and s[i]!='?' and s[i]!='*' and s[i+1]=='*' )
                while(add)
                    cout<< s[i],
                    add--;
            else if( s[i]!='?' and s[i]!='*' )
                cout<< s[i];
        }
    }

    else
    {
        for(int i=0;i<s.size();i++)
            if( s[i]!='?' and s[i]!='*' )
                cout<< s[i];
    }

}
