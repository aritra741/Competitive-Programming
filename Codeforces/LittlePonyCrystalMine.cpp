#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<n;i+=2)
    {
        int tot= n-i;
        tot/=2;
        for(int j=0;j<tot;j++)
        {
            cout<<"*";
        }
        for(int k=1;k<=i;k++)
            cout<<"D";
        for(int j=0;j<tot;j++)
            cout<<"*";
        cout<<endl;
    }

    for(int i=0;i<n;i++)
        cout<<"D";
    cout<<endl;

    for(int i=n-2;i>=1;i-=2)
    {
        int tot= n-i;
        tot/=2;
        for(int j=0;j<tot;j++)
        {
            cout<<"*";
        }
        for(int k=1;k<=i;k++)
            cout<<"D";
        for(int j=0;j<tot;j++)
            cout<<"*";
        cout<<endl;
    }
}
