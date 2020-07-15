#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[100005];

ll ncr(ll n, ll r)
{
    if(r>n-r)
        r=n-r;
    ll ans=1;

    for(int i=0; i<r; i++)
    {
        ans*=(n-i);
        ans/=(i+1);
    }

    return ans;
}

int main()
{
    ll n,d;
    cin>>n>>d;

    for(ll i=0; i<n; i++)
        cin>>arr[i];

    ll start=0, finish=0, done=-1, cnt=1, temp=0, ans=0;
    bool first=0;

    for(ll i=1; i<n; i++)
    {
        if( arr[i] - arr[start] > d )
        {
            if(cnt>=3 and arr[i-1]-arr[start]<=d and !first)
            {
                first=1;
                finish=i-1;
                ans+= ncr(cnt, 3);
            }
            else if(cnt>=3 and arr[i-1]-arr[start]<=d and first and start!=i-1)
            {
                ll excl=0;
                if(finish-start>=2)
                    excl+= ncr(finish-start+1, 3);
                ans+= ncr(cnt, 3)-excl;
                finish=i-1;
            }

            start++;
            i--;
            cnt--;

        }

        else
            cnt++;
    }


    if(arr[n-1]-arr[start]<=d and cnt>=3)
    {
        if(!first)
            ans+=ncr(cnt,3);
        else{
        ll excl=0;
        if(finish-start>=2)
            excl+= ncr(finish-start+1, 3);
        ans+= ncr(cnt, 3)-excl;
        }
    }

    cout<<ans<<endl;

}
