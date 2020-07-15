#include <bits/stdc++.h>
using namespace std;

bool primality(long long n)
{
    int x=sqrt(n);
    for(int i=2;i<=x;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

int main()
{
    long long n;
    cin>>n;
    long long temp=n;
    long long arr[3];
    if(primality(n)==1)
    {
        cout<<1<<endl<<n;
    }
    else{
    for(long long i=n-2;i>=n-500 && i>1;i--)
    {
        if(primality(i)==1)
            {
                arr[0]=i;
                temp-=i;
                break;
            }
    }
    if(primality(temp)==1)
        cout<<2<<endl<<arr[0]<<" "<<temp;
    else
    {

        for(long long i=temp-2;i>=temp-500 && i>1;i--)
    {
        if(primality(i)==1 && primality(temp-i)==1)
            {
                arr[1]=i;
                break;
            }
    }
    cout<<3<<endl<<arr[0]<<" "<<arr[1]<<" "<<temp-arr[1];
    }

    }
}
