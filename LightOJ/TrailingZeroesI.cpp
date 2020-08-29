#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

bool arr[MAX];
vector <long long> prime;
void sieve(void)
{
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<MAX;i++)
    {
        if(arr[i]==0)
        {
            prime.push_back(i);
            for(int j=2;i*j<MAX;j++)
                if(arr[i*j]==0)
                    arr[i*j]=1;
        }
    }
}

long long divcount(long long x)
{

    long long cnt=1;
    long long n=sqrt(x);
    for(long long i=0;i<=prime.size()-1 && prime[i]<=n;i++)
    {
        long long inCnt=0;

        if(x<prime[i])
            break;
        while(x%prime[i]==0)
        {

            x/=prime[i];
            inCnt++;
        }
        cnt*=(inCnt+1);

            }
    if(x>1)
        cnt*=2;
    cnt-=1;
return cnt;
}


int main()
{

    sieve();
    int tc;
    scanf("%d", &tc);
    for(int i=1;i<=tc;i++)
    {
        long long n;
        scanf("%lld", &n);
        long long div=divcount(n);
        printf("Case %d: %lld\n",i,div);
    }

}
