#include <bits/stdc++.h>
using namespace std;

long long arr[3];
long long sum[4100];

long long cnt(long long tot, long long i)
{

    if(i>=3)
        {
            if(tot==0)
                return 0;
            return -1e10;
        }

    long long t1=-1e10,t2=-1e10;
    if(sum[tot]!=-1)
        return sum[tot];
    if(tot-arr[i]>=0)
        t1=cnt(tot-arr[i], i)+1;
    t2=cnt(tot, i+1);
    sum[tot] =  max(t1,t2);
    return sum[tot];


}

int main()
{
    long long n,a,b,c;
    cin>>n>>arr[0]>>arr[1]>>arr[2];
    memset(sum, -1, sizeof(sum));
    long long ans=-1e10;
  //  sort(arr, arr+3);
    for(long long i=0;i<3;i++)
    ans=max(ans, cnt( n, i));
    cout<<ans<<endl;

}
