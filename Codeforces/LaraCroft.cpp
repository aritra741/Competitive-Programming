#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main()
{
    ull n,m,k,r,c;
    cin>>n>>m>>k;
    if(k<=n)
        r=k+1;
    else if(k<=n*m)
        r=ceil((double)(n*m-k)/n);

    if(k<n)
        c=k+1;
    else if(k<=n*m)
    {
        int t=floor(double(k/(m-1)));
        if(t%2!=0)
           {
                c=k%(m-1)+2;
           }
        else
            c=(n*m-k)%(m-1)+1;
    }

    cout<<r<<" "<<c;


}
