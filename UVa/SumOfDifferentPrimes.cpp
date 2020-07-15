#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool arr[1500];
ll dp[250][1500][15];
bool vis[250][1500][15];
vector <int> primes;
int sz;

void sieve()
{
    arr[0]=arr[1]=1;

    for(ll i=2;i<1500;i++)
    {
        if(!arr[i])
        {
            primes.push_back(i);
            for(ll j=i*i;j<1500;j+=i)
                arr[j]=1;
        }
    }
}

int n,cap;

ll rec(int i, int curr, int cnt)
{
    if(i>sz)
        return 0;
    if(cnt==n)
    {
        if(curr==cap)
            return 1;
        return 0;
    }
    if(primes[i-1]>cap)
        return 0;
    if(vis[i][curr][cnt])
        return dp[i][curr][cnt];

    int p1,p2;

    if(primes[i-1]+curr<=cap)
        p1= rec(i+1, curr+primes[i-1], cnt+1);
    else
        p1=0;
    p2= rec(i+1, curr, cnt);

    vis[i][curr][cnt]=1;

    return dp[i][curr][cnt]= p1+p2;
}

int main()
{
    sieve();
    sz=primes.size();

    while(1)
    {
        cin>>cap>>n;

        if(n+cap==0)
            break;

        cout<< rec(1, 0, 0) <<endl;

        memset(vis, 0, sizeof(vis));

    }
}
