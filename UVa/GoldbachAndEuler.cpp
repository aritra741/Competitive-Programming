#include <bits/stdc++.h>
#define ll long long
#define MX 100000505
using namespace std;

bool num[MX];
vector <int> prime;
vector <int> ::iterator it;

void sieve()
{
    num[0]= num[1]= 1;
    prime.push_back(2);

    for(ll i=3; i<MX; i++)
        if(!num[i])
        {
            prime.push_back(i);
            for(ll j=i*i; j<MX; j+=i)
                num[j]=1;
        }

}

int main()
{
    sieve();

    int n;

    while( scanf("%d", &n)==1 )
    {
        if(n<=3)
            printf("%d is not the sum of two primes!\n", n);

        else if( n & 1 )
        {
            if( !num[n-2] )
                printf("%d is the sum of 2 and %d.\n", n, n-2);
            else
                printf("%d is not the sum of two primes!\n", n);
        }

        else
        {
            bool flag=0;
            int sz= prime.size();
            int a, b;
            a= b= n/2;

            int low, high;

            it= lower_bound( prime.begin(), prime.end(), a );
            int i= it- prime.begin();

            if(prime[i]==a)
                i--;

            for(;i>=0;i--)
            {
                if(((n-prime[i])&1) and !num[n- prime[i]] )
                {
                    low=prime[i];
                    high=n-prime[i];
                    flag=1;
                    break;
                }
            }


            if(flag)
                printf("%d is the sum of %d and %d.\n", n, min(low,high), max(low,high));
            else
                printf("%d is not the sum of two primes!\n", n);
        }
    }
}
