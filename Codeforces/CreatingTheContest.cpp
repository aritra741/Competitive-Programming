#include <bits/stdc++.h>
#define ll long long
#define MX 300007

ll arr[MX];

using namespace std;
int main()
{
    ll n;
    cin>>n;

    for(ll i=0;i<n;i++)
        scanf("%lld", &arr[i]);

    ll len=1;
    ll mxlen=1;
    ll j=0;

    for(int i=0;i<n-1;i++)
    {
        if(arr[i]*2>=arr[i+1])
            len++;
        else
        {
            mxlen=max(mxlen, len);

            len=1;
        }

        //cout<<<<" "<<i<<endl;
    }
    mxlen=max(mxlen, len);
    cout<<mxlen<<endl;
}
