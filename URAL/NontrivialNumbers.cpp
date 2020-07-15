#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

vector <int> primes;

bool arr[MAX];

void sieve(void)
{
    arr[0]=1;
    arr[1]=1;
    for(int i=2; i<=MAX; i++)
    {
        if(arr[i]==0)
        {
            primes.push_back(i);
            for(int j=2; i*j<=MAX; j++)
                arr[i*j]=1;
        }
    }

}

int main()
{
    int a,b;
    cin>>a>>b;
    sieve();
    if(a==1)
    {
        cout<<1;
        return 0;
    }
    double mn=1e18;
    long long ans=0;
    for(long long i=b; i>=a; i--)
    {
        if(arr[i]==0)
        {
            cout<<i;
            return 0;
        }
        long long p=i;
        long long temp=1;
        for(int j=0;j<primes.size();j++)
        {
            if(primes[j]>p)
                break;
            long long prod=1,sum=1;
            while(p%primes[j]==0)
            {
                p/=primes[j];
                prod*=primes[j];
                sum+=prod;

            }
            temp*=sum;
//            if(i==27)
//                cout<<temp<<endl;
        }
        temp-=i;


        double th= (double)temp/(double)i;
        if(th<mn)
        {
            mn=th;
            ans=i;
        }

    }
    cout<<ans;


}
