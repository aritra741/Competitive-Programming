#include<bits/stdc++.h>
using namespace std;

int arr[55];
vector<string>v;
vector<string> ans;

int main()
{
    string s= "a";
    for( char i= 'A';i<='Z';i++ )
        s[0]= i, v.push_back(s);
    for( char i= 'A';i<='Z';i++ )
        s[0]= i, v.push_back(s);
    int j= 0;
    for( char i= 'a';i<='z';i++ )
        s[0]= i, v[j++]+= s;

    int n, k;
    cin>>n>>k;

    for( int i=0;i<n-k+1;i++ )
    {
        string s;
        cin>>s;

        if( s[0]=='Y' )
            arr[i]= 1;
    }

    j= 0;
    for( int i=0;i<n;i++ )
    {
        j= i;
        ans.push_back( v[i] );
    }

    for( int i=k-1;i<n;i++ )
    {
        if( !arr[i-(k-1)] )
            ans[i]= ans[i-k+1];
    }

    for( auto x: ans )
        cout<<x<<" ";
}
