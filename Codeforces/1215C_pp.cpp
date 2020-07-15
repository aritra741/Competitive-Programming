#include<bits/stdc++.h>
using namespace std;

deque<int>a,b, ta, tb;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s,t;

    cin>>n;
    cin>>s>>t;

    int as= 0, bs= 0, at= 0, bt= 0;

    for( int i=0; i<n; i++ )
    {
        if( s[i]=='a' )
            as++;
        else
            bs++;
        if( t[i]=='a' )
            at++;
        else
            bt++;

        if( s[i]!=t[i] )
        {
            if(s[i]=='a')
                a.push_back(i+1);
            else
                b.push_back(i+1);

            if( t[i]=='a' )
                ta.push_back(i+1);
            else
                tb.push_back(i+1);
        }
    }

    if( (as+at)&1 or (bs+bt)&1 )
        return cout<<"-1\n", 0;

    int ans= min( min( min( as, bs ), at ), bt );

    cout<< ans <<endl;

    if( as==ans )
    {
        for( int i=0; i<s.size(); i++ )
            if( s[i]=='a' and s[i]!=t[i] )
                cout<<i+1<<" "<<tb[0]<<"\n", tb.pop_front();
    }
    else if( at==ans )
    {
        for( int i=0; i<s.size(); i++ )
            if( t[i]=='a' and s[i]!=t[i] )
                cout<<b[0]<<" "<<i+1<<"\n", b.pop_front();
    }
    else if( bs==ans )
    {
        for( int i=0; i<s.size(); i++ )
            if( s[i]=='b' and s[i]!=t[i] )
                cout<<i+1<<" "<<ta[0]<<"\n", ta.pop_front();
    }
    else
    {
        for( int i=0; i<s.size(); i++ )
            if( t[i]=='b' and s[i]!=t[i] )
                cout<<a[0]<<" "<<i+1<<"\n", a.pop_front();
    }
}

