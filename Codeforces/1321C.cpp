#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    int cnt= 0;

    while(1)
    {
        char c= 1;
        for( int i=0; i<s.size(); i++ )
        {
            if( i and s[i-1]==s[i]-1 and s[i]>c )
                c= s[i];
            if( i<(int)s.size()-1 and s[i+1]==s[i]-1 and s[i]>c )
                c= s[i];
        }

        if(c==1)
            break;

        string t;

        for( int i=0;i<s.size();i++ )
        {
            if( s[i]!=c )
                t.push_back(s[i]);
            else
            {
                bool f= 1;
                if( i and s[i-1]==s[i]-1 )
                    f= 0;
                if( i+1<s.size() and s[i+1]==s[i]-1 )
                    f= 0;

                if(f)
                    t.push_back(s[i]);
                else
                    cnt++;
            }
        }

        s=t;

    }

    cout<< cnt <<endl;
}
