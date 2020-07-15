#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        map<char, int> mp;
        bool found[27];
        int cnt= 0;

        int n;
        cin>>n;

        for(int k=0;k<n;k++)
        {
            memset( found, 0, sizeof(found) );

            string s;
            cin>>s;

            for(int i=0; i<s.size(); i++)
            {
                char c= s[i];

                if( !found[ c-'a' ] )
                {
                    mp[c]++,
                    found[ c-'a' ]= 1;
                    if( mp[c]==n )
                        cnt++;
                }
            }

        }

        cout<< cnt <<endl;
    }
}
