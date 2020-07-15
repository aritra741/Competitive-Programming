#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int>v;

int main()
{
    int k;
    cin>>k;

    string s;
    cin>>s;

    ll z= 0, cnt= 0;

    for( int i=0;i<s.size();i++ )
    {
        if( s[i]=='1' )
            v.push_back(i), z+= (cnt*(cnt+1))/2, cnt= 0;
        else
            cnt++;
    }

    if(cnt)
        z+= ( cnt*(cnt+1) )/2;
    if( v.size()<k )
        return cout<<"0", 0;
    if( !k )
        return cout<<z<<endl, 0;

    ll ans= 0;

    for( int i=k-1;i<v.size();i++ )
    {
        ll agey, pore;

        if( i-k>=0 )
            agey= v[i-k+1]-v[i-k];
        else
            agey= v[i-k+1]+1;

        if( i+1<v.size() )
            pore= v[i+1]-v[i];
        else
            pore= s.size()-v[i];

        ans+= agey*pore;
    }

    cout<< ans <<endl;
}
