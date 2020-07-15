#include<bits/stdc++.h>
#define ll long long
#define mx 100007
using namespace std;

bool arr[mx];
vector<int> prime;

void sieve()
{
    arr[0]= arr[1]= 1;
    prime.push_back(2);

    for( ll i=3; i<mx; i+=2 )
    {
        if( !arr[i] )
        {
            prime.push_back(i);
            for( ll j=i*i; j<mx; j+=i )
                arr[j]= 1;
        }
    }
}

int main()
{
    sieve();
    int n;

    while( scanf("%d", &n)==1 and n )
    {
        int p= abs(n);
        vector<int> ans;
        for( ll x=0; x<prime.size() and prime[x]*prime[x]<=p; x++ )
        {
//cout<<p<<" "<<x<<" "<<prime[x]<<endl;
            while( p%prime[x]==0 )
            {
                ans.push_back(prime[x]);
                p/= prime[x];
            }
        }
//        cout<<"asdgf\n";
        int q= abs(n);

        while( p>1 and q%p==0 )
            ans.push_back(p), q/= p;

        printf("%d =", n);

        if( n<0 )
            printf(" -1 x");
        for( int i=0; i<(int)ans.size()-1; i++ )
            printf(" %d x", ans[i]);
        if( ans.size() )
            printf(" %d\n", ans[ ans.size()-1 ]);
    }
}
