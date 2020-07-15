#include <bits/stdc++.h>
#define mx 1000007
#define ll long long
#define pii pair<int, int>
using namespace std;

bool arr[mx];
vector<int> prime, cnt;

ll Pow( int x, int y )
{
    ll ans= 1;

    while(y>0)
    {
        if(y&1)
            ans*=x;
        x*=x;
        y>>=1;
    }

    return ans;
}

void sieve()
{
    arr[0]=arr[1]= 1;
    prime.push_back(2);

    for(ll i=3; i<mx; i+=2)
    {
        if(!arr[i])
        {
            prime.push_back((int)i);

            for(ll j=i*i; j<mx; j+=i)
                arr[j]= 1;
        }
    }
}

int main()
{
    sieve();
    int sz= prime.size();

    int n;
    cin>>n;

    int mn= 1;
    int Mx= 1;
    int first= n;
    bool lagbe= 0;

    for(int i=0; i<sz and prime[i]<=n; i++)
    {
        if( n%prime[i]==0 )
        {
            int y= 0;

            while(n%prime[i]==0)
                y++, n/=prime[i];

            int req= ceil(log2(y));
            int now= log2(y);

            req= 1<<req;
            now= 1<<now;
            Mx= max(Mx, req);
            mn*=prime[i];
            cnt.push_back(now);
        }
    }

    for(int i=0; i<cnt.size(); i++)
        if( cnt[i]<Mx )
        {
            lagbe= 1;
            break;
        }

    int steps= (int)log2(Mx);
    if(lagbe)
        steps++;
    steps= (arr[first] or !(first&1))? steps: 0;

    cout<< mn <<" " << steps <<endl;
}
