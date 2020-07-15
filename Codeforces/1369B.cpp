#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;

        string s;
        cin>>s;

        int last= -1;

        for( int i=0; i<n; i++ )
        {
            if(s[i]=='0')
                last= i;
        }

        int i= 0, j=1;

        while(i<last and j<last)
        {
            while( s[i]==-1 and i<last )
                i++;
            if(i==last)
                continue;
            while( s[j]==-1 and j<last )
                j++;
            if(j==last)
                continue;

            if( s[i]=='1' and s[j]=='0' )
            {
                s[j]= -1;
                j++;
            }
            else
                i++, j++;
        }

        i= last-1;
        while( i>=0 and s[i]!='0')
            s[i]= -1, i--;

        for( int i=0; i<last; i++ )
            if( s[i]!=-1 )
                cout<<s[i];

        if(last>=0)
            for( int i=last; i<n; i++ )
                cout<<s[i];
        else
            cout<<s;

        cout<<endl;
    }
}
