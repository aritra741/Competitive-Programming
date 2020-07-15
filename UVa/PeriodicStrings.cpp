#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        string s;
        cin>>s;

        int ans= 1e9;

        for( int i=1;i<=s.size();i++ )
        {
            string t= s.substr( 0, i );

            bool f= 1;
            for( int j=0;j<s.size();j+=i )
            {
                string t2= s.substr( j, i );

                if( t2!=t )
                {
                    f= 0;
                    break;
                }
            }

            if(f)
                ans= min( ans, i);
        }

        cout<< ans <<endl;

        if(tc)
            cout<<endl;
    }
}
