#include <bits/stdc++.h>
using namespace std;

map<string,string> par;
map<string,string> ::iterator it;
map<string,bool> leaf;

int main()
{
    int q;
    cin>>q;

    while(q--)
    {
        string s,t;
        cin>>s>>t;

        if( par[s][0]==0 )
            par[s]= s;
        par[t]= s;
        leaf[s]= 0;
        leaf[t]= 1;
    }

    int cnt= 0;
    for(it=par.begin();it!=par.end();it++)
        if( it->second==it->first )
            cnt++;

    cout<<cnt<<endl;

    for(it=par.begin();it!=par.end();it++)
    {
        string s= it->first;
        if( leaf[s] )
        {
            while( par[s]!=s )
                s= par[s];
            cout<<s<<" "<< it->first <<endl;
        }

    }
}
