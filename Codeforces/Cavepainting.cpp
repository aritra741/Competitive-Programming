#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main()
{
    bool flag=0;
    ull n,k;
    cin>>n>>k;
    if(n<k && n!=1)
       {
           cout<<"No";
           return 0;
       }
    else
    {
        for(int i=1;i<=k;i++)
            if(n%i!=i-1)
            {
                flag=1;
                break;
            }
    }
    if(flag==0)
        cout<<"Yes";
    else
    cout<<"No";

}
