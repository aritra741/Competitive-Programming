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

        int arr[n+5];
        string s[n+5];

        for( int i=1; i<=n; i++ )
            cin>>arr[i];

        for( int i=0; i<arr[1]; i++ )
            s[1].push_back('a');
        if(!arr[1])
            s[1].push_back('a');

        char c= 'a';

        for( int i=2; i<=n+1; i++ )
        {
            for( int j=0; j<arr[i-1]; j++ )
                s[i].push_back(s[i-1][j]);

            if(i<=n)
                for( int j= arr[i-1]; j<arr[i]; j++ )
                {
//                    cout<<i<<" e ashlo "<<j<<endl;
                    if(j<s[i-1].size())
                        while( s[i-1][j]==c )
                        {
//                            cout<<"ashchhe "<<s[i-1][j]<<" "<<c<<endl;
                            c++;

                            if(c>'z')
                                c= 'a';
                        }
                    else
                    {
                        c++;

                        if(c>'z')
                            c= 'a';
                    }


                    s[i].push_back(c);

                }

            if(s[i].empty())
            {
                while(c==s[i-1][0])
                {
                    c++;

                    if(c>'z')
                        c= 'a';
                }

                s[i].push_back(c);
            }
        }

        for( int i=1; i<=n+1; i++ )
            cout<<s[i]<<endl;
    }
}
