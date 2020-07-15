#include<bits/stdc++.h>
using namespace std;

string s;
int n,tot;
set<char>st;

bool ok( int x )
{
    map<char,int>mp;
    int cnt= 0;
    for( int i=0;i<x;i++ )
    {
        mp[ s[i] ]++;

        if( mp[ s[i] ]==1 )
            cnt++;
    }

    if( cnt==tot )
        return 1;

    for( int i=x;i<n;i++ )
    {
        mp[ s[i-x] ]--;

        if( mp[ s[i-x] ]==0 )
            cnt--;

        mp[ s[i] ]++;

        if( mp[ s[i] ]==1 )
            cnt++;

        if( cnt==tot )
            return 1;
    }

    return 0;
}

int main()
{
    cin>>n;
    cin>>s;

    for( int i=0;i<n;i++ )
        st.insert(s[i]);

    tot= st.size();

    int l= 1, r= n, ans= n;

    while( l<r-4 )
    {
        int mid= (l+r)/2;

        if( ok(mid) )
            r= mid, ans= mid;
        else
            l= mid;
    }

    while(l<=r)
    {
        if( l<ans and ok(l) )
            ans= l;
        l++;
    }

    cout<< ans <<endl;
}
