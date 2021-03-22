#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll josephus(ll n, ll k) {
    if (n == 1)
        return 0;
    if (k == 1)
        return n-1;
    if (k > n)
        return (josephus(n-1, k) + k) % n;
    ll cnt = n / k;
    ll res = josephus(n - cnt, k);
    res -= n % k;
    if (res < 0)
        res += n;
    else
        res += res / (k - 1);
    return res;
}

int main()
{
    ll n,k;

    while(cin>>n>>k and (n+k))
    {
        cout<< josephus(n,k) <<"\n";
    }
}