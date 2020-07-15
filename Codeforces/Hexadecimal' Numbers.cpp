#include <bits/stdc++.h>
using namespace std;
int n,lim, last;
string s;

int rec( int i, int sm )
{

    if( i==n )
    {
        if(sm)
            return 1;
        return 0;
    }

    int q1= 0,q2= 0;
    int for0= sm, for1= sm;
    if(i!=n-1)
    {
        if(s[lim-i-1]=='0');
        else
            for0= 1;
        q1= rec(i+1,for0);
    }

    if(s[lim-i-1]>'1')
        for1= 1;
    else if(s[lim-i-1]<'1')
        for1= 0;
    if(n!=lim)
        for1= 1;

    q2= rec(i+1,for1);


    return q1+q2;
}

int main()
{
    int m;
    cin>>m;

    stringstream ss;
    ss<<m;
    ss>>s;
    lim= log10(m)+1;
    last= m%10;
    int ans= 0;

    for(int i=1; i<=lim; i++)
    {
        n= i;
        ans+=rec(0,1);
    }

    cout<< ans <<endl;
}
