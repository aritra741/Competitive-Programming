#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int j=0; j<=n; j++)
    {
        for(int i=n-j; i>0; i--)
        {
            cout<<"  ";
        }
        for(int p=0; p<=j; p++)
            {
                    cout<<p;
                    if(j)
                        cout<<" ";
            }
        for(int k=j-1;k>=0;k--)
            {
                cout<<k;
                if(k)
                    cout<<" ";
            }

        cout<<endl;
}

    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=(i+1)*2;j++)
            cout<<" ";
        for(int p=0;p<=n-1-i;p++)
            {
                cout<<p;
                if(i!=n-1)
                    cout<<" ";
            }
        for(int k=n-i-2;k>=0;k--)
            {
                cout<<k;
                if(k)
                    cout<<" ";
            }
        cout<<endl;
    }
}
