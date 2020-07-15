#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0; n>=2; i+=2)
    {
        if(n==3)
        {
            cout<<s[i]<<s[i+1]<<s[i+2];
            break;
        }
        if(n==2)
        {
            cout<<s[i]<<s[i+1];
            n=n-2;
        }
        else
        {
            cout<<s[i]<<s[i+1]<<"-";
            n=n-2;
        }
    }
}

