#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    string s,s2;
    cin>>s;

    s2=s;
    reverse(s2.begin(),s2.end());

    int st=0;
    int mxl=0;
    bool flag=0;
    string t,t2;
    int lim=n-1;
    for(int i=1;i<=lim;i++)
    {
        t= s.substr(0, i);
        t2= s2.substr(0, i);

        reverse(t2.begin(), t2.end());

        if(t==t2 and t!="" and t2!="")
            {
                flag=1;
                mxl=i;
            }
    }

    string s3=s;

    if(t!="" and flag)
    {
        cout<<s;

        for(int i=1;i<k;i++)
            for(int j=mxl;j<n;j++)
                cout<<s[j];
        if(n==1)
            for(int i=1;i<k;i++)
            cout<<s;
    }

    else
    {
        for(int i=0;i<k;i++)
            cout<<s;
    }
}
