#include<bits/stdc++.h>
#define mx 1000007
using namespace std;

int main()
{
    string s;
    cin>>s;

    vector<int>a,b,c;

    for( int i=0;i<s.size();i++ )
    {
        if(s[i]=='a')
            a.push_back(i+1);
        if(s[i]=='b')
            b.push_back(i+1);
        if(s[i]=='c')
            c.push_back(i+1);
    }

    int lagbe= s.size()/2;
    int agey= 0, pore= s.size()+1;

    for( int i=0;i<a.size();i++ )
    {
        if( a[i]>agey and a[i]<pore )
        {

        }
    }
}
