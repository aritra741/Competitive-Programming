#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n,m;
        cin>>n>>m;

        string s[n];

        for( int i=0; i<n; i++ )
            cin>> s[i];

        set<int>st[m+1];

        for( int i=0; i<n; i++ )
            st[i].insert(s[i]);

        string ans= "";


    }
}
