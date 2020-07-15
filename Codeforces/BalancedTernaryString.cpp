#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;

    int one= 0, zero= 0, two= 0;

    for(int i=0;i<n;i++)
    {
        if( s[i]=='0' )
            zero++;
        else if(s[i]=='1')
            one++;
        else
            two++;
    }

    int req= n/3;
    int i= 0;

    while(zero<req and i<n)
    {
        if( s[i]=='2' and two>req )
            s[i]= '0', two--, zero++;
        if( s[i]=='1' and one>req )
            s[i]= '0', one--, zero++;
        i++;

    }
    i= n-1;
    while(two<req and i>=0)
    {
        if( s[i]=='0' and zero>req )
            s[i]= '2', two++, zero--;
        if( s[i]=='1' and one>req )
            s[i]= '2', one--, two++;
        i--;
    }
    i= n-1;
    while(one<req and i>=0)
    {
        if( s[i]=='2' and two>req )
            s[i]= '1', two--, one++;
        if( s[i]=='0' and zero>req )
            s[i]= '1', zero--, one++;
        i--;
    }


    cout<< s <<endl;

}
