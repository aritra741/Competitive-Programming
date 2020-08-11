#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        map<int,int>mp;
        string s;
        cin>>s;

        for( int i=0;i<s.size();i++ )
            mp[ s[i]-'a' ]++;

        int n;
        cin>>n;

        int arr[n+5];

        for( int i=0;i<n;i++ )
            cin>>arr[i];

        vector<char>ans(n+5,0);

        for( int i=25;i>=0;i-- )
        {
            vector<int>idx;

            for( int j=0;j<n;j++ )
                if( !arr[j] )
                    idx.push_back(j);

            if(mp[i]<idx.size())
                continue;

            for( auto x: idx )
            {
                ans[x]= 'a'+i;
                arr[x]= -1;

                for( int k=0;k<n;k++ )
                    arr[k]-= abs( x-k );
            }
        }

        for( int i=0;i<n;i++ )
            cout<< ans[i];

        cout<<"\n";
    }
}
