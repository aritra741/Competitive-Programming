#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    while(cin>>s and s[0]!='.')
    {
        int ans= 1;
        int len= s.size();

        for( int i=1; i<=len; i++ )
        {
            if( len%i )
                continue;

            int p= len/i;
            string t= s.substr( 0, i );

            bool f= 1;
            for( int j=0; j<s.size(); j+=i )
            {
                string t2= s.substr( j, i );

                if( t2!=t )
                {
                    f= 0;
                    break;
                }
            }

            if(f)
            {
                ans= i;
                break;
            }
        }

        printf("%d\n", (int)s.size()/ans );
    }
}

