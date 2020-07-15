/* Corrected Comments */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll k;
    cin>>k;
    string s;
    cin>>s;
    ll len=s.length();
    ll ans=0;
    ll sum=0;
    ll cnt[len+1]= {0};
    cnt[0]=1;
    for(ll i=0; i<len; i++)
    {
        sum+=s[i]-'0';
        cnt[sum]++;
    }
    if(k==0)
    {
        for(ll i=0; i<=len; i++)
            ans+=( (cnt[i]-1)*(cnt[i]) )/2;        ///cnt[i]=number of 1s
                                                   ///cnt[i]-1=number of 0s
                                                   ///n*(n+1)/2
        cout<<ans;
        return 0;
    }
    for(ll i=k; i<=len; i++)
        ans+=cnt[i]*cnt[i-k];
    cout<<ans;
    return 0;
}

