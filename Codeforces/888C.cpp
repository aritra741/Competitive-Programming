#include <bits/stdc++.h>
using namespace std;

string s;

bool valid( int k )
{
    vector<int>mp(30,0), mark(30,0);
    int cnt= 1;

    bool f= 0;
    for( int i=0; i<k; i++ )
        mp[s[i]-'a']++, mark[s[i]-'a']= 1;

    for( int i=k; i<s.size(); i++ )
    {
        mp[ s[i]-'a' ]++;
        mp[ s[i-k]-'a' ]--;

        if( !mp[ s[i-k]-'a' ] and mark[ s[i-k]-'a' ] )
            mark[ s[i-k]-'a' ]= 0;
    }

    for( int i=0; i<26; i++ )
    {
        if( mark[i] )
            f= 1;
    }

    return f;
}

int main()
{
    cin>>s;

    int low= 1, high= s.size(), ans= high;
    int k;

    while(low<high-1)
    {
        vector<int>mp(30,0), mark(30,0);
        int cnt= 1;

        k= (low+high+1)/2;

        if( valid( k ) )
            high= k;
        else
            low= k;
    }

    for( int i=low; i<=high; i++ )
    {
        if( valid( i ) )
        {
            ans= i;
            break;
        }
    }

    cout<<ans<<endl;
}
