#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,m;
    cin>>n>>m;

    string s,t;
    cin>>s>>t;

    if(n>m+1)
    {
        cout<<"NO"<<endl;
        return 0;
    }

    bool flag=0;

    size_t found= s.find("*");

    if(found!=string::npos)
        flag=1;

    if(!flag)
    {
        if(s==t)
            cout<<"YES";
        else
            cout<<"NO";
        return 0;
    }

    bool fir=0;
    flag=0;

    int i;

    for(i=0; i<n; i++)
    {
        if(s[i]=='*')
            break;
        if(s[i]!=t[i])
        {
            cout<<"NO";
            return 0;
        }

    }
    i++;

    for(int j=m-1, k=n-1; k>=i; k--,j--)
    {
        if(s[k]!=t[j])
        {
            cout<<"NO";
            return 0;
        }
    }

    cout<<"YES";

}
