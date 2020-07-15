#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    vector <int> zero, pos, neg;
    int n,t;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>t;
        if(t==0)
            zero.pb(t);
        else if(t>0)
            pos.pb(t);
        else
            neg.pb(t);
    }

    if(pos.size()>0)
    {
        if(!(neg.size() & 1))
        {
            int t=neg[neg.size()-1];
            zero.pb(t);
            neg.pop_back();
        }
    }
    else
    {
        int sz=neg.size();
        int t=neg[sz-1];
        int r=neg[sz-2];
        pos.pb(t);
        pos.pb(r);
        neg.pop_back();
        neg.pop_back();

        if( !((sz-2) & 1) )
        {
            int t=neg[sz-3];
            zero.pb(t);
            neg.pop_back();
        }
    }
    cout<<neg.size()<<" ";
    for(int i=0;i<neg.size();i++)
        cout<<neg[i]<<" ";
    cout<<endl<<pos.size()<<" ";
    for(int i=0;i<pos.size();i++)
        cout<<pos[i]<<" ";
    cout<<endl<<zero.size()<<" ";
    for(int i=0;i<zero.size();i++)
        cout<<zero[i]<<" ";
}
