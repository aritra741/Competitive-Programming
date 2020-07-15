#include <bits/stdc++.h>
using namespace std;

int n,lim;
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
    int for4= sm, for7= sm;

    if(s[lim-i-1]>'4')
        for4= 1;
    else if(s[lim-i-1]<'4')
        for4= 0;

    q1= rec(i+1,for4);

    if(s[lim-i-1]>'7')
        for7= 1;
    else if(s[lim-i-1]<'7')
        for7= 0;
    if(n!=lim)
        for7= 1;

    q2= rec(i+1,for7);

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
    int ans= 0;

    for(int i=1; i<=lim; i++)
    {
        n= i;
        ans+=rec(0,1);
    }

    cout<< ans <<endl;
}

