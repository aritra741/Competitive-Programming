#include <bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main()
{
    fast;

    int tc;
    cin>>tc;

    while(tc--)
    {
        string s;
        cin>>s;

        int a= 0, b= 0;

        for( int i=0;i<s.size();i++ )
        {
            if( s[i]=='m' )
            {
                if( i and s[i-1]=='s' )
                    s[i-1]= 'x';
                else if( i+1<s.size() and s[i+1]=='s' )
                    s[i+1]= 'x';
            }
        }

        for( auto c: s )
            if(c=='s')
                a++;
            else if(c=='m')
                b++;

        if(a==b)
            cout<<"tie\n";
        else if(a>b)
            cout<<"snakes\n";
        else
            cout<<"mongooses\n";
    }
}