#include <bits/stdc++.h>
using namespace std;
long long func(long long i,long long j)
{
    int p=min(i,j);
    int q=max(i,j);
    if(p==1)
        return 1;
    if(p==0)
        return q;
    else return func(j%i,i);
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,flag=0;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        long long gcd=arr[0];
        for(int i=1;i<n;i++)
        {
            gcd=func(gcd, arr[i]);
            if(gcd==1)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            cout<<n<<endl;
        else
            cout<<"-1"<<endl;
    }
}
