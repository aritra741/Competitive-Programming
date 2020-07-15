#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans=0,n,m;
    cin>>n>>m;
    int init=m;
    while(1)
        {
            if(n>=m)
            {
                ans+=n-m;
                break;
            }
            if(m%2==0)
                m=m/2;
            else m++;
            ans++;

        }

    cout<<ans;
}

