#include <bits/stdc++.h>
#define MX 1000000+7
using namespace std;

bool arr[MX];
vector <int> prime;

void sieve()
{
    arr[0]=arr[1]=1;

    for(long long i=2; i<MX; i++)
    {
        if(!arr[i])
        {
            prime.push_back(i);
            for(long long j=i*i; j<MX; j+=i)
                arr[j]=1;
        }
    }
}

int main()
{
    sieve();

    int sz= prime.size();

    while(1)
    {
        int n;
        scanf("%d", &n);

        if(!n)
            break;

        int t= n;
        int cnt=0;

        for(int i=0; i<sz and prime[i]<=n; i++)
        {
            if(n%prime[i]==0)
            {
                cnt++;;
                while( n%prime[i]==0 )
                    n/=prime[i];
            }
        }

        printf("%d : %d\n", t, cnt);
    }

}
