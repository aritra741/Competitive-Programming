#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[]= {1,11,111,1111,11111,111111,1111111,11111111,111111111,
            1111111111ll,11111111111ll,111111111111ll,1111111111111ll,11111111111111ll,
            111111111111111ll};
ll n;

ll rec( ll num, int cnt )
{
    cout<< num <<" "<<cnt<<endl;
    if( num==0 )
        return 0;
    if(cnt>3)
        return 1e9;
    ll ans= 1e9;

    for(int i=0;i<15;i++)
    {
        ans= min( i+1+rec( num+arr[i], cnt+1 ), ans );
        ans= min( i+1+rec( num-arr[i], cnt+1 ), ans );
    }

    return ans;
}

int main()
{
    cin>>n;

    cout<< rec( n,0 ) <<endl;
}
