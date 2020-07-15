#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pull;
vector<pull> v;
bool cmp(pull a, pull b)
{

	if(a.first==b.first){
    return a.second<b.second;
}
return a.first<b.first;

}
int main()
{
    ll n,r,avg,a,b,sum=0,ans=0,temp;
    cin>>n>>r>>avg;
    ll tot=n*avg;

    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        sum+=a;
        v.push_back(pull(b,a));
    }
    if(sum>=tot)
        cout<<"0";
    else
    {
        sort(v.begin(), v.end(), cmp);
        for(int i=0;i<n;i++)
        {

            if(sum<tot)
                {

                    temp=sum;
                    sum+=min(tot-sum, r-v[i].second);
                    ans+=v[i].first*(sum-temp);
        }
        else break;
    }


cout<<ans;
    }
}
