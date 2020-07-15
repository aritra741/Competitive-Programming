#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    ll arr[n];

    for(int i=0; i<n; i++)
        cin>>arr[i];

    string s;
    cin>>s;

    ll tot= 0;
    int l=0,r=0, cnt= 1;

    for(int i=0; i<n-1; i++)
    {
        if(cnt==1)
            l= i;
        if( s[i]!=s[i+1] )
        {
            if(cnt==1)
            {
                tot+=arr[i];
                continue;
            }

            r= i;
            sort( arr+l, arr+r+1 );

            for(int j=r; j>=max(r-k+1, l); j--)
                tot+=arr[j];

            cnt= 1;
        }

        else
            cnt++;
    }

    if( n>=2 and s[n-1]==s[n-2] )
    {
        r= n-1;
        sort( arr+l, arr+r+1 );

        for(int j=r; j>=max(r-k+1, l); j--)
            tot+=arr[j];
    }

    else if( n>=2 and s[n-1]!=s[n-2] )
        tot+=arr[n-1];

    if(n==1)
        tot= arr[0];

    cout<< tot <<endl;
}
