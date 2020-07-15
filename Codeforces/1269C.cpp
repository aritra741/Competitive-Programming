#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    string t;

    for( int i=0;i<k;i++ )
        t.push_back(s[i]);

    for( int i=k;i<n;i++ )
        t.push_back(t[i-k]);

    if( t>=s )
        return cout<<t.size()<<endl<<t<<endl, 0;

    int i= k-1;

    while(s[i]=='9')
        i--;

    if( i>=0 )
    {
        t[i]= s[i]+1;

        for( int j=i+1;j<k;j++ )
            t[j]= '0';

        for( int j=k;j<n;j++ )
            t[j]= t[j-k];
    }
    else
    {
        t.clear();
        t.push_back('1');

        for( int i=0;i<k;i++ )
            t.push_back('0');

        for( int i=k;i<n;i++ )
            t.push_back(t[i-k]);
    }

    cout<<t.size()<<endl<<t<<endl;
}
