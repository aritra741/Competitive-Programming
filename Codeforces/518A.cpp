#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    cin>>s;
    cin>>t;

    for( int i=s.size()-1;i>=0;i-- )
    {
        if( s[i]=='z' )
            s[i]= 'a';
        else
        {
            s[i]++;
            break;
        }
    }

    if( s<t )
        cout<<s<<endl;
    else
        cout<<"No such string\n";
}
