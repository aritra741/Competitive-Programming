#include <bits/stdc++.h>
#define ull unsigned long long
#define MAX 100000
#define MOD 1000000007
using namespace std;

vector<long long> prime;
bool num[MAX];

void sieve(void)
{
    num[0]=1;
    num[1]=1;
    for(int i=2;i<MAX;i++)
    {
        if(num[i]==0)
        {
            prime.push_back(i);
            for(int j=2;i*j<MAX;j++)
            {
                if(num[i*j]==0)
                    num[i*j]=1;
            }
        }
    }
}

ull power(ull x, ull y)
{
    ull res = 1;

    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % MOD;
        y = y>>1;
        x = ( x*x) % MOD;
    }
    return res;
}


int main()
{
    int tc;
    sieve();
    scanf("%d", &tc);
    ull n,m;
    for(int i=1;i<=tc;i++)
    {
        scanf("%llu %llu", &n, &m);

        ull ans=1;
        int sz=prime.size();
        ull p=n;

        for(int j=0;j<sz;j++)
        {
            bool flag=0;
            if(prime[j]>p)
                break;
            ull expo=0;
            ull temp=1;
            while(p%prime[j]==0)
                {
                    flag=1;
                    p/=prime[j];
                    expo++;
                }
            if(flag)
            {
                expo*=m;
                expo+=1;
                ull up=(power( prime [j], expo)-1)%MOD;
                ull down= (power( prime[j]-1, MOD-2 ))%MOD;
                ull s= ( (up%MOD)*(down%MOD) )%MOD;
                s= (s+MOD) %MOD;
                ans= ((ans%MOD) * (s%MOD) ) % MOD;
            }


        }
        if(p!=1){

        ull expo = m+1,up;

        if(p%MOD==0) {
            ans = 1;
        }
        else{
        up = ( power(p,expo) - 1)%MOD;
        ull  down = power(p-1,MOD-2)%MOD;
        ull s = (up * down) % MOD;
        ans =  ( (ans%MOD)*(s) ) % MOD;
        ans= (ans+MOD)%MOD;
        }
    }

        printf("Case %d: %llu\n", i, ans);

    }
}
