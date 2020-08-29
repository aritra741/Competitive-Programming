#include <bits/stdc++.h>
#define MAX 10000003
#define ll long long
using namespace std;

bool arr[MAX];
vector<int> prime;
bool isPrime(long long n)
{
    long long sq=sqrt(n);
    bool flag=1;
    for(int i=2;i<=sq;i++)
    {
        if(n%i==0)
        {
            flag=0;
            break;
        }
    }
    return flag;
}

void sieve()
{
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<MAX;i++)
    {
        if(arr[i]==0)
            {
                prime.push_back(i);
                for(int j=2;i*j<MAX;j++)
                arr[i*j]=1;
            }
    }
}

int main()
{

    sieve();
    int tc;
    ll a,b,n,mid;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        scanf("%lld", &n);
        mid=n/2;
        ll cnt=0;
        int sz=prime.size();
        for(int p=0;p<sz && prime[p]<=mid;p++)
        {

            if(arr[n-prime[p]]==0)
                cnt++;
        }
        printf("Case %d: %lld\n", i, cnt);
    }



}
